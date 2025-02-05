/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:12:54 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:50:16 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *lst, int i)
{
	t_lst	*temp;
	t_lst	*last;

	if (!lst->a || !lst->a->next)
		return ;
	temp = lst->a;
	while (temp->next && temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = lst->a;
	lst->a = last;
	if (i == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *lst, int i)
{
	t_lst	*tmp;
	t_lst	*last;

	if (!lst->b || !lst->b->next)
		return ;
	tmp = lst->b;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = lst->b;
	lst->b = last;
	if (i == 1)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_stack *lst)
{
	reverse_rotate_a(lst, 0);
	reverse_rotate_b(lst, 0);
	ft_printf("rrr\n");
}
