/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:09:09 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:02:12 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_pos(t_stack *lst, size_t *pos)
{
	t_lst	*tmp;
	size_t	m_value;
	size_t	current_pos;

	if (!lst->b)
		return (-1);
	tmp = lst->b;
	m_value = 0;
	current_pos = 0;
	*pos = 0;
	while (tmp)
	{
		if (tmp->pos > m_value)
		{
			m_value = tmp->pos;
			*pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (m_value);
}

void	max_rotate(t_stack *lst, size_t *m_p, size_t size)
{
	if (*m_p <= (size / 2))
	{
		rotate_b(lst, 1);
		(*m_p)--;
	}
	else
	{
		reverse_rotate_b(lst, 1);
		if (*m_p + 1 == size)
			*m_p = 0;
		else
			(*m_p) = (*m_p) + 1;
	}
}

void	optimize(t_stack *lst)
{
	if (lst->b && lst->b->next)
	{
		if (lst->b->pos < lst->b->next->pos)
		{
			if (!lst->b->next->next
				|| lst->b->next->pos > lst->b->next->next->pos)
				swap_a(lst, 1);
		}
	}
}
