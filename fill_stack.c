/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:38:52 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 15:19:43 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_new(char *value, int i, t_stack *lst)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
	{
		free_stack(lst);
		return (-1);
	}
	new->value = ft_atoi(value);
	if (new->value == 0 && ft_strcmp(value, "0") != 0)
	{
		free(new);
		free_stack(lst);
		return (-1);
	}
	new->pos = i;
	new->next = NULL;
	ft_pw_lstadd_front((&lst->a), new);
	return (0);
}

int	fill_stack(char **tab, t_stack *lst)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i > 0)
	{
		if (add_new(tab[i - 1], i, lst) == -1)
			return (-1);
		i--;
	}
	return (0);
}
