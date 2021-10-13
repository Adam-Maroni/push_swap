/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:50:06 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/28 13:02:18 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_print_inst_list(t_dll *inst)
{
	t_dll *start;
	if (!inst)
		return ;
	start = inst;
	printf("%s\n",inst->content);
	inst = inst->next;
	while (inst && inst != start)
	{
		printf("%s\n",inst->content);
		inst = inst->next;
	}
}


int ft_try_instr_list(t_dll *a, t_dll *b, t_dll *instr, char *stack_indicator)
{
	int rt;
	int a_indicator;
	int b_indicator;
	t_dll *cpy_a;
	t_dll *cpy_b;
	
	a_indicator = ft_strncmp(stack_indicator, "a", ft_strlen(stack_indicator));
	b_indicator = ft_strncmp(stack_indicator, "b", ft_strlen(stack_indicator));
	rt = 0;
	if ((!a && !b) || (a_indicator != 0 && b_indicator != 0))
		return (-1);
	cpy_a = ft_dll_cpy(a);
	cpy_b = ft_dll_cpy(b);
	ft_execute_instr_list(&cpy_a, &cpy_b, instr);
	if (a_indicator == 0 && ft_is_in_order(cpy_a))
		rt = 1;
	if (b_indicator == 0 && ft_is_in_order(cpy_b))
		rt = 1;
	ft_free_dll(&cpy_a);
	ft_free_dll(&cpy_b);
	return (rt);
}

void ft_execute_instr_list(t_dll **a, t_dll **b, t_dll *instr)
{
	t_dll *start;
        if (!instr)
                return ;
	start = instr;
       	ft_execute_instr(a,b,instr->content);
	instr = instr->next;
        while (instr != start)
        {
                ft_execute_instr(a,b,instr->content);
                instr = instr->next;
        }
}


void ft_fill_instr_list(t_dll **list, int x, char *instruction)
{
	//fill the instr list passed as parameters with the instruction , x times
	while (x-- > 0)
		ft_dll_addback(list, ft_dll_new(instruction));
}
