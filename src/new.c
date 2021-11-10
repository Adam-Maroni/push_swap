#include "../push_swap.h"

void	ft_push_swap(int argc, char **argv)
{
	t_dll	*a;
	t_dll	*instr;

	if (argc <= 1 || !argv || !*argv)
		return ;
	a = ft_string_tab_to_list(argc, argv);
	instr = NULL;
	if (ft_dll_size(a) <= 3)
		instr = ft_resolve_for_2_and_3(a);
	else if (ft_dll_size(a) <= 5)
		instr = ft_resolve_for_4_and_5(&a);
	else if (ft_dll_size(a) < 500)
		instr = ft_resolve_for_100(&a);
	else
		instr = ft_resolve_for_500(&a);
	ft_free_dll(&a);
	ft_clean_instr_caller(&instr);
	ft_print_inst_list(instr);
	ft_free_dll(&instr);
}

/*
Convert the string given to dll a
*/
t_dll	*ft_string_tab_to_list(int argc, char **argv)
{
	t_dll	*a;
	int		i;

	if (argc <= 1 || !argv || !*argv)
		return (NULL);
	i = 0;
	a = NULL;
	while (++i < argc)
		ft_dll_addback(&a, ft_dll_new(argv[i]));
	return (a);
}

int	ft_try_instr(t_dll *a, t_dll *b, t_dll *instr)
{
	t_dll	*cpy_a;
	t_dll	*cpy_b;
	int		rt;

	cpy_a = ft_dll_cpy(a);
	cpy_b = ft_dll_cpy(b);
	ft_execute_instr_list(&cpy_a, &cpy_b, instr);
	rt = ft_is_over(cpy_a, cpy_b);
	ft_free_dll(&cpy_a);
	ft_free_dll(&cpy_b);
	return (rt);
}

/*
This function return the necessary instructioons to:
-Put element_b on top of stack b
-Put the smallest element that is larger than b , from a, on top of stack a
-Push from b to a
-Reverse the rotation of a so stack a is back in ascending order

There are two requirements for this function to works properly:
List a must not be empty
List a must be in ascending order
*/
t_dll	*ft_rt_place_b_to_a(t_dll **top_a, t_dll **top_b, char *element_b)
{
	t_dll	*instr;
	t_dll	*cpy_b;
	t_dll	*cpy_a;
	t_dll	*smallest;

	if (!element_b || !top_b || !top_a)
		return (NULL);
	instr = NULL;
	smallest = NULL;
	cpy_b = ft_dll_cpy(*top_b);
	cpy_a = ft_dll_cpy(*top_a);
	ft_execute_and_add(&instr, ft_rt_best_rotation(cpy_b, element_b, 'b'),
		&cpy_a, &cpy_b);
	if (ft_rt_smallest_larger(cpy_a, element_b))
		ft_execute_and_add(&instr,
			ft_rt_best_rotation(cpy_a,
				(*ft_rt_smallest_larger(cpy_a, element_b))->content, 'a'),
			&cpy_a, &cpy_b);
	ft_execute_and_add(&instr, ft_dll_new("pa"), &cpy_a, &cpy_b);
	ft_execute_and_add(&instr,
		ft_rt_best_rotation(cpy_a, (*ft_rt_smallest(cpy_a))->content, 'a'),
		&cpy_a, &cpy_b);
	ft_free_dll(&cpy_b);
	ft_free_dll(&cpy_a);
	return (instr);
}

/*
Return the number of instructions necessary
to place element_b to list a (on its right position)

Requirements:
-Neither inputs must be null or points to null
*/
size_t	ft_estimate_cost(t_dll **a, t_dll **b, t_dll **element_b)
{
	t_dll	*instr;
	int		rt;

	if (!a || !*a || !b || !*b || !element_b || !*element_b
		|| ft_rt_element(*a, (*element_b)->content)
		|| !ft_rt_element(*b, (*element_b)->content))
		return (0);
	instr = ft_rt_place_b_to_a(a, b, (*element_b)->content);
	rt = ft_dll_size(instr);
	ft_free_dll(&instr);
	return (rt);
}
