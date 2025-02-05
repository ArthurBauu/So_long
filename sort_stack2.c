/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:51:01 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:59 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *lst, size_t *rot_count, size_t stack_size)
{
	while (*rot_count < stack_size)
	{
		reverse_rotate_a(lst, 1);
		(*rot_count)++;
	}
	*rot_count = 0;
}

t_lst	*find_next_min(t_lst *head)
{
	t_lst	*tmp;
	t_lst	*min;

	tmp = head;
	min = NULL;
	while (tmp)
	{
		if (tmp->pos == 0 && (!min || tmp->value < min->value))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	assign_position(int size, t_stack *lst)
{
	t_lst	*tmp;
	t_lst	*min;
	size_t	pos;

	pos = 1;
	tmp = lst->a;
	while (tmp)
	{
		tmp->pos = 0;
		tmp = tmp->next;
	}
	while (pos <= (size_t)size)
	{
		min = find_next_min(lst->a);
		if (min)
		{
			min->pos = pos;
			pos++;
		}
	}
}

int	block_rotate(t_stack *lst, size_t *r_t, size_t s_s)
{
	rotate_a(lst, 1);
	(*r_t)++;
	return (*r_t >= s_s);
}

void	push_back_a(t_stack *lst)
{
	size_t	max_position;
	size_t	size;

	while (lst->b)
	{
		size = count_value(lst->b);
		max_pos(lst, &max_position);
		while (max_position > 0)
			max_rotate(lst, &max_position, size);
		optimize(lst);
		push_a(lst);
	}
}
