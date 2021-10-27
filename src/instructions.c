/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:05:20 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/26 20:15:18 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_execute_instr(t_dll **a, t_dll **b, char *instr)
{
	if (!ft_strncmp(instr, "pa", ft_strlen(instr)))
		ft_px(b, a);
	else if (!ft_strncmp(instr, "pb", ft_strlen(instr)))
		ft_px(a, b);
	else if (!ft_strncmp(instr, "sa", ft_strlen(instr)))
		ft_sx(*a);
	else if (!ft_strncmp(instr, "sb", ft_strlen(instr)))
		ft_sx(*b);
	else if (!ft_strncmp(instr, "ss", ft_strlen(instr)))
		ft_ss(*a, *b);
	else if (!ft_strncmp(instr, "ra", ft_strlen(instr)))
		ft_rx(a);
	else if (!ft_strncmp(instr, "rb", ft_strlen(instr)))
		ft_rx(b);
	else if (!ft_strncmp(instr, "rr", ft_strlen(instr)))
		ft_rr(a, b);
	else if (!ft_strncmp(instr, "rra", ft_strlen(instr)))
		ft_rrx(a);
	else if (!ft_strncmp(instr, "rrb", ft_strlen(instr)))
		ft_rrx(b);
	else if (!ft_strncmp(instr, "rrr", ft_strlen(instr)))
		ft_rrr(a, b);
	else
		return ;
}

/* Add to the end of dst (which is a list of instruction) new (another list)
 * after having executed new on list a and b */
void	ft_execute_and_add(t_dll **dst, t_dll *new, t_dll **a, t_dll **b)
{
	t_dll	*tmp;

	if (!dst || !new || !a || !b)
		return ;
	tmp = new->next;
	ft_execute_instr_list(a, b, new);
	ft_dll_addback(dst, new);
	while (tmp != new)
	{
		ft_dll_addback(dst, tmp);
		tmp = tmp->next;
	}
}
