/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/18 12:18:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_over(t_dll *a, t_dll *b)
{
	if (!b && a && ft_is_in_order(a))
		return (1);
	return (0);
}

int	ft_is_in_order(t_dll *dll)
{
	int	*serie;
	int	rt;
	int	i;
	int	y;

	rt = 1;
	if (!dll)
		return (0);
	if (dll == dll->next)
		return (1);
	serie = ft_dll_to_int(dll);
	i = 0;
	while (i < ft_dll_size(dll) - 1)
	{
		y = i + 1;
		while (y < ft_dll_size(dll))
		{
			if (serie[i] > serie[y])
				rt = 0;
			y++;
		}
		i++;
	}
	free(serie);
	return (rt);
}

int	*ft_dll_to_int(t_dll *dll)
{
	int		*serie;
	int		i;
	t_dll	*start;

	i = 0;
	serie = (int *)ft_calloc(ft_dll_size(dll), sizeof(int));
	serie[i] = ft_atoi(dll->content);
	i++;
	start = dll;
	dll = dll->next;
	while (dll != start)
	{
		serie[i] = ft_atoi(dll->content);
		i++;
		dll = dll->next;
	}
	return (serie);
}

int	ft_dll_size(t_dll *start)
{
	int		i;
	t_dll	*tmp;

	i = 1;
	if (!start)
		return (0);
	tmp = start;
	while (start->next && start->next != tmp)
	{
		i++;
		start = start->next;
	}
	return (i);
}
