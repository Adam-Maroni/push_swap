/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:24:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/03 12:37:10 by amaroni          ###   ########.fr       */
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

/* Among element with values larger than input,
 send back the address of smallest one */
t_dll	**ft_rt_smallest_larger(t_dll *dll, char *value)
{
	t_dll	**rt;
	t_dll	**tmp;
	int		smallest_larger;

	if (!dll || !value)
		return (NULL);
	rt = ft_rt_largest(dll);
	smallest_larger = ft_atoi((*rt)->content);
	tmp = &(dll->next);
	while (*tmp != dll)
	{
		if (ft_atoi((*tmp)->content) > ft_atoi(value)
			&& ft_atoi((*tmp)->content) < smallest_larger)
		{
			rt = tmp;
			smallest_larger = ft_atoi((*rt)->content);
		}
		tmp = &((*tmp)->next);
	}
	if (ft_atoi((*rt)->content) < ft_atoi(value))
		return (NULL);
	return (rt);
}
