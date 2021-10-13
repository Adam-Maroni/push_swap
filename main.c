/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:26:59 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/26 11:11:31 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_dll *a;

	a = NULL;
	if (!ft_is_input_correct(argv, argc))
	{
		printf("PROBLEME");
		return (0);
	}
	a = ft_argv_to_a(argv, argc);
	if (ft_is_in_order(a))
	{
		ft_free_dll(&a);
		return (0);
	}
	ft_push_swap(&a);
	ft_free_dll(&a);
	return (0);
}
