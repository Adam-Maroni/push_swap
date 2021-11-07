/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:08:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/07 21:53:33 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Copy the dll in input, order it and return that copy
*/
t_dll	*ft_rt_order_dll(t_dll *dll)
{
	t_dll	*cpy;
	t_dll	*tmp1;
	t_dll	*tmp2;

	if (!dll)
		return (NULL);
	cpy = ft_dll_cpy(dll);
	tmp1 = cpy;
	while (tmp1 != cpy->previous)
	{
		tmp2 = tmp1->next;
		while (tmp2 != cpy)
		{
			if (ft_atoi(tmp1->content) > ft_atoi(tmp2->content))
				ft_dll_switch_content(tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (cpy);
}

/*
Get an unordered dll as input, return the median value from that list
*/
int	ft_rt_median(t_dll *dll)
{
	t_dll	*ord_dll;
	int		i;

	i = 0;
	ord_dll = ft_rt_order_dll(dll);
	while (++i <= ft_dll_size(ord_dll) / 2)
		ord_dll = ord_dll->next;
	i = ft_atoi(ord_dll->content);
	ft_free_dll(&ord_dll);
	return (i);
}
