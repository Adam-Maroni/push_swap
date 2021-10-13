#include "../push_swap.h"


t_dll *ft_intelligent_sort(t_dll **a,t_dll **b)
{
	t_dll *instr;
	t_dll *cpy_a;
	int median;

	median = ft_median(*a);
	instr = NULL;
	if (!a || !*a)
		return (NULL);
	cpy_a =ft_dll_cpy(*a);
	while (ft_dll_size(cpy_a) > 3)
		if (ft_min_median_max(cpy_a,*a))
			ft_exe_and_add_instr(&instr, ft_dll_new("ra"), &cpy_a, b);
		else
			ft_exe_and_add_instr(&instr, ft_dll_new("pb"), &cpy_a, b);
	if (!ft_is_in_order(cpy_a))
		ft_exe_and_add_instr(&instr, ft_sort_for_3(cpy_a,*b, "a"), &cpy_a ,b);
	while (ft_dll_size(*b) > 0)
		ft_exe_and_add_instr(&instr, ft_gen_b2a_instr(cpy_a,*b,median,1), &cpy_a,b);
	ft_free_dll(&cpy_a);
	return (instr);
}

t_dll *ft_gen_b2a_instr(t_dll *a, t_dll *b, int median, int x)
{
	t_dll *instr;
	t_dll *cpy_b;

	if (x > ft_dll_size(a))
		return (NULL);
	instr = NULL;
	cpy_b = ft_dll_cpy(b);
	if(ft_atoi(cpy_b->content) < median)
		ft_fill_instr_list(&instr, x, "ra");
	else
		ft_fill_instr_list(&instr, x, "rra");
	ft_dll_addback(&instr, ft_best_rotation(&cpy_b, ft_atoi(cpy_b->content), "b"));
	ft_dll_addback(&instr, ft_dll_new("pa"));
	if(ft_atoi(cpy_b->content) < median)
		ft_fill_instr_list(&instr, x, "rra");
	else
		ft_fill_instr_list(&instr, x+1, "ra");
	ft_free_dll(&cpy_b);
	if (ft_try_instr_list(a,b,instr,"a"))
		return (instr);
	ft_free_dll(&instr);
	return (ft_gen_b2a_instr(a,b,median, ++x));
}

int ft_estimate_cost(t_dll **a, t_dll **b, int value) 
{
	int cost;
	t_dll *instr;

	instr = ft_gen_b2a_instr(*a,*b,value, 1);
	cost = ft_dll_size(instr);
	ft_free_dll(&instr);
	return (cost);
}

t_dll *ft_best_rotation(t_dll **dll, int value, char *stack_indicator)
{
	t_dll *start;
	t_dll *instr;
	int rx;
	int rrx;

	rx = 0;
	rrx = 0;
	instr = NULL;
	start = *dll;
	while (ft_atoi((*dll)->content) != value)
		rx += ft_rx(dll);
	*dll = start;
	while (ft_atoi((*dll)->content) != value)
		rrx += 	ft_rrx(dll);
	*dll = start;
	if (rx < rrx)
		ft_fill_instr_list(&instr,rx,ft_strjoin("r",stack_indicator));
	else
		ft_fill_instr_list(&instr,rrx,ft_strjoin("rr",stack_indicator));
	return (instr);
}




t_dll *ft_smallest_larger(t_dll *dll, int value)
{
	t_dll *marked;
	t_dll *start;

	if (!dll)
		return (NULL);
	marked = NULL;
	start = dll;
	if (ft_atoi(dll->content) > value)
		marked = dll;
	dll = dll->next;
	while (dll != start)
	{
		if (marked && ft_atoi(dll->content) < ft_atoi(marked->content) && ft_atoi(dll->content) > value)
				marked = dll;
		else if (!marked && ft_atoi(dll->content) > value)
				marked = dll;
		dll = dll->next;
	}
	return (marked);
}


t_dll *ft_sort_for_3(t_dll *a, t_dll *b, char *stack_indicator)
{
	t_dll *instr;

	instr = NULL;
	ft_dll_addback(&instr, ft_dll_new("rra"));
	if (ft_try_instr_list(a,b,instr,stack_indicator))
		return (instr);// success
	ft_dll_change_content(instr, "ra");
	if (ft_try_instr_list(a,b,instr,stack_indicator))
		return (instr);// success
	ft_dll_change_content(instr, "sa");
	if (ft_try_instr_list(a,b,instr,stack_indicator))
		return (instr);// success
	ft_dll_addback(&instr, ft_dll_new("ra"));
	if (ft_try_instr_list(a,b,instr,stack_indicator))
		return (instr);// success
	ft_dll_change_content(instr->next, "rra");
	if (ft_try_instr_list(a,b,instr,stack_indicator))
		return (instr);// success
	ft_free_dll(&instr);
	return (NULL);
}

void ft_dll_change_content(t_dll *dll, char *new_content)
{
	free(dll->content);
	dll->content = ft_strdup(new_content);
}



char *ft_revert_rotate(t_dll *instr)
{
	if (ft_strncmp(instr->content, "rra", ft_strlen(instr->content)) == 0)
			return ("ra");
	if (ft_strncmp(instr->content, "ra", ft_strlen(instr->content)) == 0)
			return ("rra");
	if (ft_strncmp(instr->content, "sa", ft_strlen(instr->content)) == 0)
			return ("sa");
	if (ft_strncmp(instr->content, "rrb", ft_strlen(instr->content)) == 0)
			return ("rb");
	if (ft_strncmp(instr->content, "rb", ft_strlen(instr->content)) == 0)
			return ("rrb");
	if (ft_strncmp(instr->content, "sb", ft_strlen(instr->content)) == 0)
			return ("sb");
	return (NULL);
}
