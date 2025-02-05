/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:41 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 16:44:40 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_lst
{
	int				value;
	size_t			pos;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack
{
	t_lst			*a;
	t_lst			*b;
}					t_stack;

typedef struct s_block
{
	size_t			size;
	size_t			start;
	size_t			end;
	size_t			pivot;
	size_t			rot_count;
	size_t			stack_size;
}					t_block;

int					already_sorted(t_stack *lst);
int					push_swap(int argc, char **argv);
int					fill_stack(char **tab, t_stack *lst);

/*TRIE*/

void				sort_three(t_stack *lst);
void				sort_five(t_stack *lst);
void				sort_stack(int argc, t_stack *lst);
int					check_nb_value(t_stack *lst);
void				assign_position(int size, t_stack *lst);
int					pivot_f(t_stack *lst, size_t start, size_t end);
void				block_init(int size, t_block *block);
void				block_u(t_stack *lst, t_block *block);
void				rotate(t_stack *lst, size_t *rot_count, size_t stack_size);
int					block_rotate(t_stack *lst, size_t *r_t, size_t s_s);
int					max_pos(t_stack *lst, size_t *pos);
void				max_rotate(t_stack *lst, size_t *m_p, size_t size);
void				optimize(t_stack *lst);
void				push_back_a(t_stack *lst);
void				sorting(size_t size, t_stack *lst);

/*--PARSING--*/
int					check_args(int argc, char **argv, t_stack *lst);
int					is_only_int(char **str);
char				**test_argc_2(char *str);
int					is_valid_int(long i);
char				**test_argc_more(int argc, char **argv);
char				**fill_tab(char **tab, char **argv, int argc);
int					is_duplicate(char **str);
int					is_valid_int_str(char *str);
int					is_only_space(char *str);

/*--OPERATION--*/

void				swap_a(t_stack *lst, int i);
void				swap_b(t_stack *lst, int i);
void				push_a(t_stack *lst);
void				push_b(t_stack *lst);
void				rotate_a(t_stack *lst, int i);
void				rotate_b(t_stack *lst, int i);
void				rotate_a_b(t_stack *lst);
void				reverse_rotate_a(t_stack *lst, int i);
void				reverse_rotate_b(t_stack *lst, int i);
void				reverse_rotate_a_b(t_stack *lst);

/*--LIST--*/

void				ft_pw_lstadd_front(t_lst **lst, t_lst *new);
void				ft_pw_lstadd_back(t_lst **lst, t_lst *new);
void				free_stack(t_stack *lst);
void				print_stack(t_lst *stack);
int					count_value(t_lst *list);
void				free_a_b(t_stack *lst);

#endif