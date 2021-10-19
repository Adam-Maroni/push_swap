/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:33:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/18 10:41:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_px(t_dll **src, t_dll **dst)
{
	char	*new_content;

	if (!src || !*src)
		return ;
	new_content = ft_strdup((*src)->content);
	ft_dll_delone(src);
	ft_dll_addback(dst, ft_dll_new(new_content));
	ft_rrx(dst);
}
