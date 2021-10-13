/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:33:03 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/25 12:34:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll *ft_argv_to_a(char **argv, int argc)
{
	int i;	
	t_dll *a;

	i = 0;
	a = NULL;
	while (++i <= argc - 1)
		ft_dll_addback(&a, ft_dll_new(argv[i]));
	return (a);
}
