/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:21:34 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 14:17:38 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(long i)
{
	if (i < INT_MIN || i > INT_MAX)
		return (-1);
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_lst	*temp;

	while (stack->a)
	{
		temp = stack->a;
		stack->a = stack->a->next;
		free(temp);
	}
}

int	count_value(t_lst *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	print_stack(t_lst *stack)
{
	t_lst	*current;

	current = stack;
	if (current == NULL)
	{
		printf("Pile vide\n");
		return ;
	}
	while (current != NULL)
	{
		printf("Valeur: %d, Position: %zu\n", current->value, current->pos);
		current = current->next;
	}
}

int	is_valid_int_str(char *str)
{
	int	k;

	k = 0;
	if (str[k] == '+' || str[k] == '-')
		k++;
	while (str[k])
	{
		if (str[k] < '0' || str[k] > '9')
			return (0);
		k++;
	}
	return (1);
}
