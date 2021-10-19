/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:29:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/18 09:52:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sx(t_dll *start)
{
	if (start != start->next)
		ft_dll_switch_content(start, start->next);
}

void	ft_ss(t_dll *a, t_dll *b)
{
	ft_sx(a);
	ft_sx(b);
}

void	ft_dll_switch_content(t_dll *one, t_dll *two)
{
	char	*tmp;

	tmp = ft_strdup(one->content);
	free(one->content);
	one->content = ft_strdup(two->content);
	free(two->content);
	two->content = ft_strdup(tmp);
	free(tmp);
}
