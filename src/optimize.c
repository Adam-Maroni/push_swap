/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/06 05:47:43 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_opposite_instr_adjacent(t_dll *instr)
{
	t_dll	*one;
	t_dll	*two;

	one = instr;
	two = instr->next;
	if (two)
	{
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
	}
	return (0);
}

char	*ft_combine_instr(t_dll *instr)
{
	t_dll	*one;
	t_dll	*two;

	one = instr;
	two = instr->next;
	if (two)
	{
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
	}
	return (NULL);
}

t_dll	*ft_clean_instr(t_dll **instr)
{
	t_dll	*one;
	t_dll	*rt;

	rt = NULL;
	if (!instr || !*instr)
		return (NULL);
	(*instr)->previous->next = NULL;
	one = *instr;
	while (one)
		if (ft_is_opposite_instr_adjacent(one))
			one = one->next->next;
	else if (ft_combine_instr(one))
	{
		ft_dll_addback(&rt, ft_dll_new(ft_combine_instr(one)));
		one = one->next->next;
	}
	else
	{
		ft_dll_addback(&rt, ft_dll_new(one->content));
		one = one->next;
	}
	(*instr)->previous->next = (*instr);
	ft_free_dll(instr);
	return (rt);
}
