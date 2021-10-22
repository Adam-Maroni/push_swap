/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:33:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/22 13:13:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll	*ft_resolve_for_2_and_3(t_dll *a)
{
	t_dll	*instr;

	instr = NULL;
	if (!ft_is_in_order(a))
	{
		ft_dll_addback(&instr, ft_dll_new("sa"));
	}
	return (instr);
}

int	ft_try_instr(t_dll *a, t_dll *b, t_dll *instr)
{
	t_dll	*cpy_a;
	t_dll	*cpy_b;
	int		rt;

	if (!instr || (!a && !b))
		return (-1);
	cpy_a = ft_dll_cpy(a);
	cpy_b = ft_dll_cpy(b);
	ft_execute_instr_list(&cpy_a, &cpy_b, instr);
	rt = ft_is_over(cpy_a, cpy_b);
	ft_free_dll(&cpy_a);
	ft_free_dll(&cpy_b);
	return (rt);
}
