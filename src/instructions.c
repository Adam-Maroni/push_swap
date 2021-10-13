/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:05:20 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/25 22:34:57 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void ft_execute_instr(t_dll **a, t_dll **b, char *instr)
{
	if (!ft_strncmp(instr, "pa", ft_strlen(instr)))
		ft_px(b,a);
	else if (!ft_strncmp(instr, "pb", ft_strlen(instr)))
		ft_px(a,b);
	else if (!ft_strncmp(instr, "sa", ft_strlen(instr)))
		ft_sx(*a);
	else if (!ft_strncmp(instr, "sb", ft_strlen(instr)))
		ft_sx(*b);
	else if (!ft_strncmp(instr, "ss", ft_strlen(instr)))
		ft_ss(*a,*b);
	else if (!ft_strncmp(instr, "ra", ft_strlen(instr)))
		ft_rx(a);
	else if (!ft_strncmp(instr, "rb", ft_strlen(instr)))
		ft_rx(b);
	else if (!ft_strncmp(instr, "rr", ft_strlen(instr)))
		ft_rr(a,b);
	else if (!ft_strncmp(instr, "rra", ft_strlen(instr)))
		ft_rrx(a);
	else if (!ft_strncmp(instr, "rrb", ft_strlen(instr)))
		ft_rrx(b);
	else if (!ft_strncmp(instr, "rrr", ft_strlen(instr)))
		ft_rrr(a,b);
	else
		return ;
}

void ft_exe_and_add_instr(t_dll **dst, t_dll *instr, t_dll **a, t_dll **b)
{
	if (!instr)
		return ;
	ft_execute_instr_list(a,b,instr);
	ft_dll_addback(dst, instr);
}
