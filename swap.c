/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:24:25 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:51:51 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_swap(t_lst *a, t_lst *b)
{
	t_lst	temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
	b->next = a->next;
	a->next = b;
}

void	swap_a(t_stack *lst, int i)
{
	if (!lst->a || !lst->a->next)
		return ;
	lst_swap(lst->a, lst->a->next);
	if (i == 1)
		ft_printf("sa\n");
}

void	swap_b(t_stack *lst, int i)
{
	if (!lst->b || !lst->b->next)
		return ;
	lst_swap(lst->b, lst->b->next);
	if (i == 1)
		ft_printf("sb\n");
}

void	swap_a_b(t_stack *lst)
{
	swap_a(lst, 0);
	swap_b(lst, 0);
	ft_printf("ss\n");
}
