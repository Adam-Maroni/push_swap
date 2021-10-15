/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:39:41 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/15 13:33:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_dll{
	struct s_dll	*next;
	struct s_dll	*previous;
	char			*content;
}		t_dll;

/* dll.c */
t_dll	*ft_dll_new(char *new_content);
void	ft_dll_addback(t_dll **adll, t_dll *new);
void	ft_free_dll(t_dll **dll);

#endif
