#include "../push_swap.h"

/* 
Choose the best algortihm based on the length of input
void	ft_push_swap(int argc, char **argv)
{
	t_dll *a;
	t_dll *instr;

	//convert argv to list	
	a = ft_string_tab_to_list(int argc, char **argv);
	if (ft_dll_size(a) <= 3)
		instr = ft_resolve_for_2_and_3(a);
	else if (ft_dll_size(a) <= 5)
		instr = ft_resolve_for_4_and_5(a);
	else if (ft_dll_size(a) < 500)
		instr = ft_resolve_for_100(a);
	else
		instr = ft_resolve_for_500(a);
	ft_free_dll(&a);
	ft_print_inst_list(instr);
	ft_free_dll(&instr);
}
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
