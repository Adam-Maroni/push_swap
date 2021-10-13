/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:33:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/28 13:05:57 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void ft_dll_delone(t_dll **dll)
{
	t_dll *tmp;

	tmp = (*dll);
	*dll = (*dll)->next;
	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	free(tmp->content);
	free(tmp);
}

void ft_px(t_dll **src, t_dll **dst)
{
	char *new_content;

	if (ft_dll_size(*src) == 0)
		return ;
	new_content = ft_strdup((*src)->content);
	if (ft_dll_size(*src) == 1)
		ft_free_dll(src);
	else
		ft_dll_delone(src);
	ft_dll_addback(dst, ft_dll_new(new_content));
	ft_rrx(dst);
}

