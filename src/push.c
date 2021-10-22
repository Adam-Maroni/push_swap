/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:33:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/21 20:00:22 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_px(t_dll **src, t_dll **dst)
{
	if (!src || !*src)
		return ;
	ft_dll_addback(dst, ft_dll_new((*src)->content));
	ft_dll_delone(src);
	ft_rrx(dst);
}
