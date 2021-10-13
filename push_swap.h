/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:39:41 by amaroni           #+#    #+#             */
/*   Updated: 2021/09/29 15:53:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_dll{
	struct s_dll *next;
	struct s_dll *previous;
	char *content;
}t_dll;

/* dll.c */
t_dll *ft_dll_new(char *new_content);
void ft_dll_addback(t_dll **adll, t_dll *new);
void ft_free_dll(t_dll **dll);
int ft_dll_size(t_dll *start);
t_dll *ft_dll_cpy(t_dll *orig);

/* swap.c */
void ft_sx(t_dll *start);
void ft_ss(t_dll *a, t_dll *b);
void ft_dll_switch_content(t_dll *one, t_dll *two);

/* rotate.c */
int ft_rx(t_dll **start);
int ft_rrx(t_dll **start);
void ft_rr(t_dll **a, t_dll **b);
void ft_rrr(t_dll **a, t_dll **b);

/* push.c */
void ft_px(t_dll **src, t_dll **dst);
void ft_dll_delone(t_dll **dll);

/* input_checking.c */
int ft_is_input_correct(char **input, int argc);
int ft_is_only_digit(char **input, int i);
int ft_is_a_int(char **input, int i);
int ft_is_there_dupplicates(char **input, int argc, int i);

/* push_swap.c */
void ft_push_swap(t_dll **a);


/* optimize.c */
t_dll *ft_optimize_instr(t_dll **instr);
char *ft_combo_maker(char *instr1, char *instr2);

/* checking.c */
int ft_is_over(t_dll *a, t_dll *b);
int ft_is_in_order(t_dll *dll);
int *ft_dll_to_int(t_dll *dll);

/* instructions.c */
void ft_execute_instr(t_dll **a, t_dll **b, char *instr);
t_dll *ft_last_instr(t_dll *instr);
void ft_exe_and_add_instr(t_dll **dst, t_dll *instr, t_dll **a, t_dll **b);

/* instructions_list.c */
void ft_print_inst_list(t_dll *inst);
int ft_try_instr_list(t_dll *a, t_dll *b, t_dll *instr, char *stack_indicator);
void ft_execute_instr_list(t_dll **a, t_dll **b, t_dll *instr);
void ft_fill_instr_list(t_dll **list, int x, char *instruction);

/* median.c */
int ft_median(t_dll *dll);
t_dll *ft_rt_ordered_list(t_dll *dll);
int ft_min_median_max(t_dll *element, t_dll *list);
void ft_order_int(int **serie, int size);

/* conversion.c */
t_dll *ft_argv_to_a(char **argv, int argc);

/* a classer.c */
t_dll *ft_intelligent_sort(t_dll **a,t_dll **b);
t_dll *ft_gen_b2a_instr(t_dll *a, t_dll *b, int median, int x);
int ft_estimate_cost(t_dll **a, t_dll **b, int value) ;
t_dll *ft_best_rotation(t_dll **dll, int value, char *stack_indicator);
t_dll *ft_sort_for_3(t_dll *a, t_dll *b, char *stack_indicator);
void ft_dll_change_content(t_dll *dll, char *new_content);
t_dll *ft_smallest_larger(t_dll *dll, int value);

#endif

