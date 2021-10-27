/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:24:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/27 11:26:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Send back the address of the largest element of list dll */
t_dll	**ft_rt_largest(t_dll *dll)
{
	t_dll	**tmp;
	t_dll	**rt;

	if (!dll)
		return (NULL);
	rt = &dll;
	tmp = &(dll->next);
	while (*tmp != dll)
	{
		if (ft_atoi((*tmp)->content) > ft_atoi((*rt)->content))
			rt = tmp;
		tmp = &((*tmp)->next);
	}
	return (rt);
}

/* Send back the address of the smallest element of list dll */
t_dll	**ft_rt_smallest(t_dll *dll)
{
	t_dll	**tmp;
	t_dll	**rt;

	if (!dll)
		return (NULL);
	rt = &dll;
	tmp = &(dll->next);
	while (*tmp != dll)
	{
		if (ft_atoi((*tmp)->content) < ft_atoi((*rt)->content))
			rt = tmp;
		tmp = &((*tmp)->next);
	}
	return (rt);
}

/* Send back the address of an element (if present) of list dll,
 * whith "value" as its content */
t_dll	**ft_rt_element(t_dll *dll, char *value)
{
	t_dll	**tmp;
	t_dll	**rt;

	if (!dll || !value)
		return (NULL);
	rt = &dll;
	tmp = &(dll->next);
	while (*tmp != dll)
	{
		if (ft_atoi((*tmp)->content) == ft_atoi(value))
			rt = tmp;
		tmp = &((*tmp)->next);
	}
	if (ft_atoi((*rt)->content) == ft_atoi(value))
		return (rt);
	return (NULL);
}
