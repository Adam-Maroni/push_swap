/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/08 01:48:41 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
todel
Convert a dll to a string with \n between instructions.
*/
char	*ft_dll_to_str(t_dll *dll)
{
	char	*str;
	t_dll	*start;

	if (!dll)
		return (NULL);
	start = dll;
	str = (char *)ft_calloc(5 * sizeof(char), ft_dll_size(dll));
	ft_strlcat(str, dll->content, ft_strlen(str) + ft_strlen(dll->content) + 1);
	ft_strlcat(str, "\n", ft_strlen(str) + 2);
	dll = dll->next;
	while (dll != start)
	{
		ft_strlcat(str, dll->content,
			ft_strlen(str) + ft_strlen(dll->content) + 1);
		dll = dll->next;
		ft_strlcat(str, "\n", ft_strlen(str) + 2);
	}
	return (str);
}

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
			if (tmp != tmp->next)
				ft_dll_delone(&(tmp->next));
			ft_dll_delone(&tmp);
			tmp = start->next;
			continue ;
		}
		tmp = tmp->next;
	}
}

/*
Call ft_clean_instr with predefined pattern
*/
void ft_clean_instr_caller(t_dll **dll)
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


//void ft_combo_maker()
