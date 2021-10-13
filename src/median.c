/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:04:27 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/29 13:06:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_median(t_dll *dll)
{
	t_dll *ord;
	int i;
	int median;

	ord = ft_rt_ordered_list(dll);
	i = ft_dll_size(dll);
	while (i-- > ft_dll_size(dll) / 2)
		ord = ord->next;
	median = ft_atoi(ord->content);
	ft_free_dll(&ord);
	return (median);
}

void ft_order_int(int **serie, int size)
{
	int tmp;
	int i;
	int y;
	
	i = -1;
	while (++i < size - 1)
	{
		y = i;
		while (++y < size)
		{
			if ((*serie)[i] > (*serie)[y])
			{
				tmp = (*serie)[i];
				(*serie)[i] = (*serie)[y];
				(*serie)[y] = tmp;
			}
		}
	}
}

t_dll *ft_rt_ordered_list(t_dll *dll)
{
	int i;
	int *serie;
	t_dll *ord;

	if (!dll || ft_dll_size(dll) == 0)
		return (NULL);
	if (ft_dll_size(dll) == 1)
		return (ft_dll_cpy(dll));
	ord = NULL;
	serie = ft_dll_to_int(dll);
	ft_order_int(&serie, ft_dll_size(dll));
	i = -1;
	while (++i < ft_dll_size(dll))
		ft_dll_addback(&ord, ft_dll_new(ft_itoa(serie[i])));
	free(serie);
	return (ord);
}

int ft_min_median_max(t_dll *element, t_dll *list)
{
	t_dll *ord;
	int rt;

	rt = 0;
	ord = ft_rt_ordered_list(list);
	if (ft_atoi(ord->content) == ft_atoi(element->content) || ft_atoi(element->content) == ft_median(list) || ft_atoi(element->content) == ft_atoi(ord->previous->content))
		rt = 1;
	ft_free_dll(&ord);
	return (rt);
}
