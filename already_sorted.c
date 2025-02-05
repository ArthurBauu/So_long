/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/12/20 18:03:38 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/20 22:07:42 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_stack *lst)
{
	t_lst	*current;

	if (!lst || !lst->a || lst->b != NULL)
		return (-1);
	current = lst->a;
	while (current->next != NULL)
	{
		if (current->value < current->next->value)
			current = current->next;
		else
			return (-1);
	}
	return (0);
}
