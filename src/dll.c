/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:38:18 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/28 17:03:53 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll *ft_dll_new(char *new_content)
{
	t_dll *new;
	new = (t_dll*)ft_calloc(1,sizeof(t_dll));
	if (!new)
		return (NULL);
	new->content = ft_strdup((char*)new_content);
	new->next = new;
	new->previous = new;
	return (new);
}

void ft_dll_addback(t_dll **adll, t_dll *new)
{
	t_dll *dll;
	t_dll *start;

	if (!new)
		return ;
	if (!adll || !*adll)
		*adll = new;
	else
	{
		dll = (*adll)->previous;
		dll->next = new;
		new->previous = dll;
		start = new;
		while (new->next != start)
			new = new->next;
		new->next = *adll;
		(*adll)->previous = new;
	}
}


void ft_free_dll(t_dll **dll)
{
	if (!(*dll))
		return ;
	if ((*dll)->previous->next)
		(*dll)->previous->next = NULL;
	while ((*dll)->next)
	{
		(*dll) = (*dll)->next;
		free((*dll)->previous->content);
		free((*dll)->previous);
	}
	free((*dll)->content);
	free((*dll));
	*dll = NULL;
}

int ft_dll_size(t_dll *start)
{
	int i;
	t_dll *tmp;
	
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

t_dll *ft_dll_cpy(t_dll *orig)
{
	t_dll *cpy;
	t_dll *start;	

	if (!orig)
		return (NULL);
	cpy = NULL;
	start = orig;
	ft_dll_addback(&cpy, ft_dll_new(start->content));
	orig = orig->next;
	while (orig && orig != start)
	{
		ft_dll_addback(&cpy, ft_dll_new(orig->content));
		orig = orig->next;
	}
	return (cpy);
}
