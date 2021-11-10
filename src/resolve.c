/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:33:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/10 20:47:21 by amaroni          ###   ########.fr       */
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

/* 
Must push everything from a to b until a is only 3 elements long
Resolve a if not in order
found_cheapest of b and push it back to a
*/
t_dll	*ft_resolve_for_100(t_dll **a)
{
	t_dll	*instr;
	t_dll	*b;
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
	ft_execute_and_add(&instr, ft_resolve_for_2_and_3(*a), a, &b);
	while (ft_dll_size(b) > 0)
		ft_execute_and_add(&instr, ft_rt_place_b_to_a(a, &b,
				(*ft_rt_largest(b))->content), a, &b);
	ft_free_dll(&b);
	return (instr);
}
