/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:50:06 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/10 21:41:54 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_inst_list(t_dll *inst)
{
	t_dll	*start;

	if (!inst)
		return ;
	start = inst;
	printf("%s\n", inst->content);
	inst = inst->next;
	while (inst && inst != start)
	{
		printf("%s\n", inst->content);
		inst = inst->next;
	}
}

void	ft_execute_instr_list(t_dll **a, t_dll **b, t_dll *instr)
{
	t_dll	*start;

	if (!instr || !a || !b)
		return ;
	start = instr;
	ft_execute_instr(a, b, instr->content);
	instr = instr->next;
	while (instr != start)
	{
		ft_execute_instr(a, b, instr->content);
		instr = instr->next;
	}
}
