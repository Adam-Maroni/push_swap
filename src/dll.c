/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:56:23 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/14 17:26:43 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_dll(t_dll **dll)
{
	t_dll	**last;
	t_dll	*tmp;
	char	*content;

	if (!dll || !*dll)
		return ;
	last = (t_dll **)malloc(sizeof(t_dll *));
	*last = (*dll)->previous;
	(*last)->next = NULL;
	while ((*dll) != *last)
	{
		(*dll) = (*dll)->next;
		content = ((*dll)->previous->content);
		free(content);
		(*dll)->previous->content = NULL;
		tmp = ((*dll)->previous);
		free(tmp);
		(*dll)->previous = NULL;
	}
	content = (*last)->content;
	free(content);
	(*last)->content = NULL;
	free(*last);
	*last = NULL;
	free(last);
}
