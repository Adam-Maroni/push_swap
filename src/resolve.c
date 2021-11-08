/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:33:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/08 01:53:11 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll	*ft_resolve_for_2_and_3(t_dll *a)
{
	t_dll	*instr;

	instr = NULL;
	if (ft_is_in_order(a))
		return (NULL);
	ft_dll_addback(&instr, ft_dll_new("rra"));
	if (ft_try_instr(a, NULL, instr))
		return (instr);
	ft_change_content(instr, "ra");
	if (ft_try_instr(a, NULL, instr))
		return (instr);
	ft_change_content(instr, "sa");
	if (ft_try_instr(a, NULL, instr))
		return (instr);
	ft_dll_addback(&instr, ft_dll_new("ra"));
	if (ft_try_instr(a, NULL, instr))
		return (instr);
	ft_change_content(instr->next, "rra");
	if (ft_try_instr(a, NULL, instr))
		return (instr);
	ft_free_dll(&instr);
	return (NULL);
}

t_dll	*ft_resolve_for_4_and_5(t_dll **a)
{
	t_dll	*instr;
	t_dll	**smallest;
	t_dll	**b;
	t_dll	*cpy;

	if (!a || ft_is_in_order(*a))
		return (NULL);
	instr = NULL;
	b = (t_dll **)calloc(sizeof(t_dll *), 1);
	*b = NULL;
	cpy = ft_dll_cpy(*a);
	while (ft_dll_size(cpy) > 3)
	{
		smallest = ft_rt_smallest(cpy);
		ft_execute_and_add(&instr,
			ft_rt_best_rotation(cpy, (*smallest)->content, 'a'), &cpy, b);
		ft_execute_and_add(&instr, ft_dll_new("pb"), &cpy, b);
	}
	ft_execute_and_add(&instr, ft_resolve_for_2_and_3(cpy), &cpy, b);
	while (ft_dll_size(cpy) != ft_dll_size(*a))
		ft_execute_and_add(&instr, ft_dll_new("pa"), &cpy, b);
	free(b);
	ft_free_dll(&cpy);
	return (instr);
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

/* 
Must push everything from a to b until a is only 3 elements long
Resolve a if not in order
found_cheapest of b and push it back to a
*/
t_dll	*ft_resolve_for_100(t_dll **a)
{
	t_dll	*instr;
	t_dll	*b;
	t_dll	*cheapest;
	int		median;

	if (!a || !*a || ft_is_in_order(*a))
		return (NULL);
	instr = NULL;
	b = NULL;
	while (ft_dll_size(*a) > 3)
	{
		median = ft_rt_median(*a);
		while (ft_atoi((*ft_rt_smallest(*a))->content) <= median)
			if (ft_atoi((*a)->content) <= median)
				ft_execute_and_add(&instr, ft_dll_new("pb"), a, &b);
			else 
				ft_execute_and_add(&instr, ft_dll_new("ra"), a, &b);
	}
	if (!ft_is_in_order(*a))
		ft_execute_and_add(&instr, ft_resolve_for_2_and_3(*a), a, &b);
	while (ft_dll_size(b) > 0)
	{
		cheapest = ft_found_cheapest(a, &b);
		ft_execute_and_add(&instr, ft_rt_place_b_to_a(a, &b, cheapest->content),
			a, &b);
	}
	ft_free_dll(&b);
	return (instr);
}
