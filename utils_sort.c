/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:26:16 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:02:30 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_size(int size)
{
	if (size <= 101)
		return (13);
	if (size <= 499)
		return (20);
	return (29);
}

void	block_init(int size, t_block *block)
{
	block->size = get_best_size(size);
	block->start = 0;
	block->rot_count = 0;
}

void	block_u(t_stack *lst, t_block *block)
{
	block->stack_size = count_value(lst->a);
	block->end = block->start + block->size;
	block->pivot = pivot_f(lst, block->start, block->end);
}
