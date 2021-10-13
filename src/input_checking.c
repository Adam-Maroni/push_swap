/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:37:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/22 18:37:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int ft_is_input_correct(char **input, int argc)
{
	int i;

	i = 1;
	if (argc == 1)
		return (0);
	while(i < argc)
	{
		if (!ft_is_only_digit(input, i))
			return (0);
		if (!ft_is_a_int(input,i))
			return (0);
		if (ft_is_there_dupplicates(input, argc, i))
			return (0);
		i++;
	}
	return (1);
}

int ft_is_only_digit(char **input, int i)
{
	//is it only digit
	int y;

	y = 0;
	while (input[i][y])
	{
		if (!ft_isdigit(input[i][y]) && !ft_issign(input[i][y]))
			return (0);
		y++;
	}
	return (1);
}


int ft_is_a_int(char **input, int i)
{
	//is it bigger than INT_MAX or smaller than INT_MIN
	if (ft_atoll(input[i]) > INT_MAX || ft_atoll(input[i]) < INT_MIN)
		return (0);
	return (1);
}

int ft_is_there_dupplicates(char **input, int argc, int i)
{
	//Check for dupplicates
	int z;
	z = i + 1;	
	while (z < argc)
		if (ft_atoi(input[i]) == ft_atoi(input[z]))
			return (1); 
		else
			z++;
	return (0);
}
