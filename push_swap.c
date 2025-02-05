/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:51 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 16:50:29 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb_value(t_stack *lst)
{
	int	size;

	size = count_value(lst->a);
	if (size <= 3)
		sort_three(lst);
	else if (size <= 5)
		sort_five(lst);
	else
	{
		assign_position(size, lst);
		sorting(size, lst);
	}
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_stack	lst;

	if (!argv)
		return (-1);
	lst.a = NULL;
	lst.b = NULL;
	if (check_args(argc, argv, &lst) != 1)
	{
		ft_printf("Error\n");
		free_a_b(&lst);
		return (-1);
	}
	if (already_sorted(&lst) == 0)
	{
		free_a_b(&lst);
		return (0);
	}
	check_nb_value(&lst);
	free_a_b(&lst);
	return (0);
}
