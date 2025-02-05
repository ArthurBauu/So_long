/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:55:34 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 13:00:25 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*list managing for push swap*/

#include "push_swap.h"

void	ft_pw_lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	if (new->next != NULL)
	{
		ft_printf("Erreur : l'élément 'new' est déjà connecté à une liste.\n");
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_pw_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	if (new->next != NULL)
	{
		ft_printf("Erreur : l'élément 'new' est déjà connecté à une liste.\n");
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	lst_free(t_lst **lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}

void	free_a_b(t_stack *lst)
{
	lst_free(&lst->a);
	lst_free(&lst->b);
}
