/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:22:42 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/29 17:23:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_cleanse_instr(char *one, char *two)
{
	if (!ft_strncmp(one, "ra", 2) && !ft_strncmp(two, "rra", 3))
		return (1);
	if (!ft_strncmp(one, "rra", 3) && !ft_strncmp(two, "ra", 2))
		return (1);
	if (!ft_strncmp(one, "rb", 2) && !ft_strncmp(two, "rrb", 3))
		return (1);
	if (!ft_strncmp(one, "rrb", 3) && !ft_strncmp(two, "rb", 2))
		return (1);
	if (!ft_strncmp(one, "sa", 2) && !ft_strncmp(two, "sa", 2))
		return (1);
	if (!ft_strncmp(one, "sa", 2) && !ft_strncmp(two, "sa", 2))
		return (1);
	if (!ft_strncmp(one, "sb", 2) && !ft_strncmp(two, "sb", 2))
		return (1);
	if (!ft_strncmp(one, "sb", 2) && !ft_strncmp(two, "sb", 2))
		return (1);
	return (0);
}

t_dll *ft_optimize_instr(t_dll **instr)
{
	t_dll *new;
	t_dll *tmp;

	new = NULL;
	if (!instr || !*instr || ft_dll_size(*instr) <= 2)
		return (NULL);
	ft_dll_addback(&new, ft_dll_new((*instr)->content));
	tmp = (*instr)->next;
	(*instr)->previous->next = NULL;
	while (tmp)
	{
		if (tmp->next && ft_cleanse_instr(tmp->content, tmp->next->content))
			tmp = tmp->next->next;
		else
		{
			ft_dll_addback(&new, ft_dll_new(tmp->content));
			tmp = tmp->next;
		}
	}
	ft_free_dll(instr);
	return (new);
}

char *ft_combo_maker(char *one, char *two)
{
	if ((!ft_strncmp(one, "ra", 3) && !ft_strncmp(two, "rb", 3)) || (!ft_strncmp(two, "ra", 3) && !ft_strncmp(one, "rb", 3)))
		return ("rr");
	if ((!ft_strncmp(one, "rra", 3) && !ft_strncmp(two, "rrb", 3)) || (!ft_strncmp(two, "rra", 3) && !ft_strncmp(one, "rrb", 3)))
		return ("rrr");
	if ((!ft_strncmp(one, "sa", 3) && !ft_strncmp(two, "sb", 3)) || (!ft_strncmp(two, "sa", 3) && !ft_strncmp(one, "sb", 3)))
		return ("ss");
	return (NULL);
}




