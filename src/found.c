/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:24:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/05 22:02:43 by amaroni          ###   ########.fr       */
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
	if (ft_atoi((*tmp)->content) > ft_atoi(value)
		&& ft_atoi((*tmp)->content) < smallest_larger)
		rt = tmp;
	if (ft_atoi((*rt)->content) < ft_atoi(value))
		return (NULL);
	return (rt);
}

/*
This functions goes through the list b 
and return the element which require
the lesser number of instruction to be transfer correctly to list a.

Requirements:
-Neither a nor b must be empty
*/

t_dll	*ft_rt_cheapest(t_dll **a, t_dll **b)
{
	t_dll	*tmp;
	t_dll	*cheapest;

	if (!a || !*a || !b || !*b)
		return (NULL);
	cheapest = *b;
	tmp = (*b)->next;
	while (tmp != *b)
	{
		if (ft_estimate_cost(a, b, &tmp) < ft_estimate_cost(a, b, &cheapest))
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
