/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:33:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/27 18:30:22 by amaroni          ###   ########.fr       */
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

t_dll	*ft_resolve_for_4(t_dll **a)
{
	t_dll	*instr;
	t_dll	**smallest;
	t_dll	**b;

	instr = NULL;
	if (!a || ft_is_in_order(*a))
		return (NULL);
	b = (t_dll **)calloc(sizeof(t_dll *), 1);
	*b = NULL;
	smallest = ft_rt_smallest(*a);
	ft_execute_and_add(&instr,
		ft_rt_best_rotation(*a, (*smallest)->content, 'a'), a, b);
	ft_execute_and_add(&instr, ft_dll_new("pb"), a, b);
	ft_execute_and_add(&instr, ft_resolve_for_2_and_3(*a), a, b);
	ft_execute_and_add(&instr, ft_dll_new("pa"), a, b);
	free(b);
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
