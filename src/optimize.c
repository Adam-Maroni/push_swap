/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/10 21:42:27 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Suppress from dll instr1 and instr2 when they follow each other.
*/
void	ft_clean_instr(t_dll **dll, char *instr1, char *instr2)
{
	t_dll	*start;
	t_dll	*tmp;

	if (!dll || !*dll || !instr1 || !instr2)
		return ;
	start = *dll;
	tmp = start->next;
	while (tmp != start)
	{
		if (!ft_strncmp(tmp->content, instr1, 4)
			&& !ft_strncmp(tmp->next->content, instr2, 4))
		{
			if (tmp->next != start)
				ft_dll_delone(&(tmp->next));
			else
				break ;
			ft_dll_delone(&tmp);
			tmp = start;
		}
		tmp = tmp->next;
	}
}

/*
Call ft_clean_instr with predefined pattern
*/
void	ft_clean_instr_caller(t_dll **dll)
{
	if (!dll || !*dll)
		return ;
	ft_clean_instr(dll, "ra", "rra");
	ft_clean_instr(dll, "rra", "ra");
	ft_clean_instr(dll, "rb", "rrb");
	ft_clean_instr(dll, "rrb", "rb");
	ft_clean_instr(dll, "sa", "sa");
	ft_clean_instr(dll, "sb", "sb");
	ft_clean_instr(dll, "pa", "pb");
	ft_clean_instr(dll, "pb", "pa");
	ft_clean_instr(dll, "rr", "rrr");
	ft_clean_instr(dll, "rrr", "rr");
	ft_clean_instr(dll, "ss", "ss");
}
