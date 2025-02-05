/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:29:46 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:50:22 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *lst)
{
	t_lst	*temp;

	if (!lst->b)
		return ;
	temp = lst->b;
	lst->b = lst->b->next;
	temp->next = NULL;
	ft_pw_lstadd_front(&(lst->a), temp);
	ft_printf("pa\n");
}

void	push_b(t_stack *lst)
{
	t_lst	*temp;

	if (!lst->a)
		return ;
	temp = lst->a;
	lst->a = lst->a->next;
	temp->next = NULL;
	ft_pw_lstadd_front(&(lst->b), temp);
	ft_printf("pb\n");
}
