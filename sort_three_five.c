/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:38:52 by arbaudou          #+#    #+#             */
/*   Updated: 2025/02/05 20:11:50 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *lst)
{
	if (!lst->a->next)
		return ;
	if (count_value(lst->a) == 2)
	{
		swap_a(lst, 1);
		return ;
	}
	if (lst->a->value > lst->a->next->value && 
			lst->a->value > lst->a->next->next->value)
	{
		rotate_a(lst, 1);
		if (lst->a->value > lst->a->next->value)
			swap_a(lst, 1);
	}
	else if (lst->a->next->value > lst->a->next->next->value)
	{
		reverse_rotate_a(lst, 1);
		if (lst->a->value > lst->a->next->value)
			swap_a(lst, 1);
	}
	else if (lst->a->value > lst->a->next->value)
		swap_a(lst, 1);
}


int	find_smallest(t_lst *a)
{
	int	smallest;

	smallest = a->value;
	while (a)
	{
		if (a->value < smallest)
			smallest = a->value;
		a = a->next;
	}
	return (smallest);
}

void	push_smallest_to_b(t_stack *lst, int smallest)
{
	t_lst	*current;
	int		pos;

	pos = 0;
	current = lst->a;
	while (current && current->value != smallest)
	{
		current = current->next;
		pos++;
	}
	if (pos <= 2)
	{
		while (pos-- > 0)
			rotate_a(lst, 1);
	}
	else
	{
		while (pos++ < count_value(lst->a))
			reverse_rotate_a(lst, 1);
	}
	push_b(lst);
}

void	sort_five(t_stack *lst)
{
	int	smallest;
	int	seccond_smallest;

	if (count_value(lst->a) == 4)
	{
		smallest = find_smallest(lst->a);
		push_smallest_to_b(lst, smallest);
		sort_three(lst);
		push_a(lst);
		return ;
	}
	smallest = find_smallest(lst->a);
	push_smallest_to_b(lst, smallest);
	seccond_smallest = find_smallest(lst->a);
	push_smallest_to_b(lst, seccond_smallest);
	sort_three(lst);
	push_a(lst);
	push_a(lst);
}
