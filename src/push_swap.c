/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:26:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/29 15:54:29 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_push_swap(t_dll **a)
{
	t_dll *instr;
	t_dll *b;

	instr = NULL;
	b = NULL;
	if (ft_dll_size(*a) == 2)
		printf("sa\n");
	else if (ft_dll_size(*a) == 3)
		instr = ft_sort_for_3(*a,b,"a");
	else
		instr = ft_intelligent_sort(a,&b);
	instr = ft_optimize_instr(&instr);
	ft_print_inst_list(instr);
	ft_free_dll(&instr);
	ft_free_dll(&b);
}


