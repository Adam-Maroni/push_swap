/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:39:41 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/10 20:54:23 by amaroni          ###   ########.fr       */
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
void	ft_execute_and_add(t_dll **dst, t_dll *new, t_dll **a, t_dll **b);
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
void	ft_clean_instr(t_dll **dll, char *instr1, char *instr2);
void	ft_clean_instr_caller(t_dll **dll);
char	*ft_dll_to_str(t_dll *dll);
/* resolve.c */
t_dll	*ft_resolve_for_2_and_3(t_dll *a);
t_dll	*ft_resolve_for_4_and_5(t_dll **a);
t_dll	*ft_resolve_for_100(t_dll **a);
t_dll	*ft_resolve_for_500(t_dll **a);

/* found.c */
t_dll	**ft_rt_largest(t_dll *dll);
t_dll	**ft_rt_smallest(t_dll *dll);
t_dll	**ft_rt_element(t_dll *dll, char *value);
t_dll	**ft_rt_smallest_larger(t_dll *dll, char *value);
t_dll	*ft_found_cheapest(t_dll **a, t_dll **b);

/* rotation_tools.c */
void	ft_fill_rx(t_dll **instr, size_t nb, char stack_indicator);
void	ft_fill_rrx(t_dll **instr, size_t nb, char stack_indicator);
t_dll	*ft_rt_best_rotation(t_dll *dll, char *value, char stack_indicator);

/* new.c */
void	ft_push_swap(int argc, char **argv);
t_dll	*ft_string_tab_to_list(int argc, char **argv);
size_t	ft_estimate_cost(t_dll **a, t_dll **b, t_dll **element_b);
int		ft_try_instr(t_dll *a, t_dll *b, t_dll *instr);
t_dll	*ft_rt_place_b_to_a(t_dll **top_a, t_dll **top_b, char *element_b);

/* median.c */
t_dll	*ft_rt_order_dll(t_dll *dll);
int		ft_rt_median(t_dll *dll, size_t scale);
#endif
