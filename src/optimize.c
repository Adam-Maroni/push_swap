/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/19 15:25:33 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_opposite_instr_adjacent(t_dll *instr)
{
	t_dll	*one;
	t_dll	*two;

	one = instr;
	two = instr->next;
	if ((!ft_strncmp("ra", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rra", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rra", one->content, ft_strlen(one->content))
			&& !ft_strncmp("ra", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rrb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rrb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("sa", one->content, ft_strlen(one->content))
			&& !ft_strncmp("sa", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("sb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("sb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rr", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rrr", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rrr", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rr", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("ss", one->content, ft_strlen(one->content))
			&& !ft_strncmp("ss", two->content, ft_strlen(two->content))))
		return (1);
	return (0);
}

char	*ft_combine_instr(t_dll *instr)
{
	t_dll	*one;
	t_dll	*two;

	one = instr;
	two = instr->next;
	if ((!ft_strncmp("ra", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("ra", two->content, ft_strlen(two->content))))
		return ("rr");	
	if ((!ft_strncmp("rra", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rrb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("rrb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("rra", two->content, ft_strlen(two->content))))
		return ("rrr");
	if ((!ft_strncmp("sa", one->content, ft_strlen(one->content))
			&& !ft_strncmp("sb", two->content, ft_strlen(two->content)))
		|| (!ft_strncmp("sb", one->content, ft_strlen(one->content))
			&& !ft_strncmp("sa", two->content, ft_strlen(two->content))))
		return ("ss");
	return (NULL);
}

t_dll	*ft_clean_instr(t_dll **instr)
{
	t_dll *start;
	t_dll *one;
	t_dll *two;
	t_dll *rt;
	rt = NULL;
	if (!instr || !*instr)
		return (NULL);
	if (*instr == (*instr)->next)
		return (*instr);
	start = *instr;
	start->previous->next = NULL;
	one = start;
	two = one->next;
	while (one && two)
	{
		if (ft_is_opposite_instr_adjacent(one))
			one = two->next;
		else if (ft_combine_instr(one)) 
			ft_dll_addback(&rt, ft_dll_new(ft_combine_instr(one)));
		else
			ft_dll_addback(&rt, ft_dll_new(one->content));
		one = two;
		two = one->next;
	}
	(*instr)->previous->next = start;
	ft_free_dll(instr);
	return (rt);
}

