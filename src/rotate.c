/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:31:01 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/25 14:14:05 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_rx(t_dll **start)
{
	if (*start)
	{
		*start = (*start)->next;
		return (1);
	}
	return (0);
}


int ft_rrx(t_dll **start)
{
	if (*start)
	{
		*start = (*start)->previous;
		return (1);
	}
	return (0);
}

void ft_rr(t_dll **a, t_dll **b)
{
	ft_rx(a);
	ft_rx(b);
}

void ft_rrr(t_dll **a, t_dll **b)
{
	ft_rrx(a);
	ft_rrx(b);
}
