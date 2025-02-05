/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:55 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:02:39 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_block(t_stack *lst, size_t *b_s, size_t pivot, size_t *r_t)
{
	push_b(lst);
	if (lst->b->pos < pivot)
		rotate_b(lst, 1);
	(*b_s)++;
	*r_t = 0;
}

int	pivot_f(t_stack *lst, size_t start, size_t end)
{
	t_lst	*tmp;
	size_t	min;
	size_t	max;

	tmp = lst->a;
	min = end;
	max = start;
	while (tmp && tmp->pos >= start && tmp->pos <= end)
	{
		if (tmp->pos < min)
			min = tmp->pos;
		if (tmp->pos > max)
			max = tmp->pos;
		tmp = tmp->next;
	}
	return ((min + max) / 2);
}

void	block_sort(t_stack *lst, t_block *block)
{
	if (lst->a->pos <= block->end)
	{
		if (block->rot_count > block->stack_size / 2)
			rotate(lst, &block->rot_count, block->stack_size);
		push_block(lst, &block->start, block->pivot, &block->rot_count);
	}
	else if (block_rotate(lst, &block->rot_count, block->stack_size))
	{
		block->start += block->size;
		block->rot_count = 0;
	}
}

void	sort_stack(int size, t_stack *lst)
{
	t_block	block;

	block_init(size, &block);
	while (lst->a)
	{
		block_u(lst, &block);
		block_sort(lst, &block);
	}
}

void	sorting(size_t size, t_stack *lst)
{
	sort_stack(size, lst);
	push_back_a(lst);
}
