/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:44:02 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:54:21 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *lst, int i)
{
	t_lst	*temp;

	if (!lst->a || !lst->a->next)
		return ;
	temp = lst->a;
	lst->a = lst->a->next;
	temp->next = NULL;
	ft_pw_lstadd_back(&lst->a, temp);
	if (i == 1)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *lst, int i)
{
	t_lst	*temp;

	if (!lst->b || !lst->b->next)
		return ;
	temp = lst->b;
	lst->b = lst->b->next;
	temp->next = NULL;
	ft_pw_lstadd_back(&lst->b, temp);
	if (i == 1)
		ft_printf("rb\n");
}

void	rotate_a_b(t_stack *lst)
{
	rotate_a(lst, 0);
	rotate_b(lst, 0);
	ft_printf("rb\n");
}
