/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:39:41 by amaroni           #+#    #+#             */
/*   Updated: 2021/10/21 12:41:07 by amaroni          ###   ########.fr       */
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
t_dll	*ft_dll_cpy(t_dll *orig);
void	ft_dll_delone(t_dll **dll);
void	ft_free_dll(t_dll **dll);
/* instructions.c */
void	ft_execute_instr(t_dll **a, t_dll **b, char *instr);
/* push.c */
void	ft_px(t_dll **src, t_dll **dst);
/* rotate.c */
int		ft_rx(t_dll **start);
int		ft_rrx(t_dll **start);
void	ft_rr(t_dll **a, t_dll **b);
void	ft_rrr(t_dll **a, t_dll **b);
/* swap.c */
void	ft_sx(t_dll *start);
void	ft_ss(t_dll *a, t_dll *b);
void	ft_dll_switch_content(t_dll *one, t_dll *two);
/* input_checking.c */
int		ft_is_input_correct(char **input, int argc);
int		ft_is_only_digit(char **input, int i);
int		ft_is_a_int(char **input, int i);
int		ft_is_there_dupplicates(char **input, int argc, int i);
/* checking.c */
int		ft_is_over(t_dll *a, t_dll *b);
int		ft_is_in_order(t_dll *dll);
int		*ft_dll_to_int(t_dll *dll);
int		ft_dll_size(t_dll *start);
void	ft_change_content(t_dll *ptr, char *new);
/* instructions_list.c */
void	ft_print_inst_list(t_dll *inst);
void	ft_execute_instr_list(t_dll **a, t_dll **b, t_dll *instr);
/* optimize.c */
t_dll	*ft_clean_instr(t_dll **instr);
int		ft_is_opposite_instr_adjacent(t_dll *instr);
char	*ft_combine_instr(t_dll *instr);
/* resolve.c */
t_dll	*ft_resolve_for_2_and_3(t_dll *a);
int	ft_try_instr(t_dll *a, t_dll *b, t_dll *instr);


#endif
