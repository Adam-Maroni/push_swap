/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:56:23 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/15 20:21:53 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll	*ft_dll_new(char *new_content)
{
	t_dll	*new;

	new = (t_dll *)ft_calloc(1, sizeof(t_dll));
	if (!new)
		return (NULL);
	new->content = ft_strdup((char *)new_content);
	new->next = new;
	new->previous = new;
	return (new);
}

void	ft_dll_addback(t_dll **adll, t_dll *new)
{
	t_dll	*last;

	if (!new)
		return ;
	if (!adll || !(*adll))
		*adll = new;
	else
	{
		last = (*adll)->previous;
		new->previous = last;
		last->next = new;
		new->next = (*adll);
		(*adll)->previous = new;
	}
}

t_dll	*ft_dll_cpy(t_dll *orig)
{
	t_dll	*cpy;
	t_dll	*start;	

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

void	ft_dll_delone(t_dll **dll)
{
	t_dll	*next;
	t_dll	*previous;
	t_dll	*element;

	if (!dll || !(*dll))
		return ;
	element = *dll;
	next = element->next;
	previous = element->previous;
	element->previous->next = next;
	element->next->previous = previous;
	free(element->content);
	free(element);
}

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
