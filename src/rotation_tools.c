/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:24:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/27 18:30:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* fill the list instr with a number nb of ra or rb instructions */
void	ft_fill_rx(t_dll **instr, size_t nb, char stack_indicator)
{
	if ((stack_indicator != 'a' && stack_indicator != 'b') || !instr)
		return ;
	while (nb-- > 0)
		if (stack_indicator == 'a')
			ft_dll_addback(instr, ft_dll_new("ra"));
	else
		ft_dll_addback(instr, ft_dll_new("rb"));
}

/* fill the list instr with a number nb of rra or rrb instructions */
void	ft_fill_rrx(t_dll **instr, size_t nb, char stack_indicator)
{
	if ((stack_indicator != 'a' && stack_indicator != 'b') || !instr)
		return ;
	while (nb-- > 0)
		if (stack_indicator == 'a')
			ft_dll_addback(instr, ft_dll_new("rra"));
	else
		ft_dll_addback(instr, ft_dll_new("rrb"));
}

/* Found the best type of rotation to put element on top of dll
 * and return the list of instruction needed */
t_dll	*ft_rt_best_rotation(t_dll *dll, char *value, char stack_indicator)
{
	t_dll	*instr;
	t_dll	*cpy;
	int		i;

	instr = NULL;
	cpy = NULL;
	i = 0;
	if (!dll || !value || (stack_indicator != 'a' && stack_indicator != 'b')
		|| !ft_rt_element(dll, value))
		return (NULL);
	cpy = ft_dll_cpy(dll);
	while (ft_strncmp(cpy->content, value, ft_strlen(value)))
	{
		cpy = cpy->next;
		i++;
	}
	if (i < ft_dll_size(cpy) / 2)
		ft_fill_rx(&instr, i, stack_indicator);
	else
		ft_fill_rrx(&instr, ft_dll_size(cpy) - i, stack_indicator);
	ft_free_dll(&cpy);
	return (instr);
}
