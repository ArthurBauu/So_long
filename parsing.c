/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:51:42 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 16:50:37 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check(int argc, char **argv)
{
	char	**tab;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		tab = test_argc_2(str);
		if (tab == NULL)
		{
			free(tab);
			return (NULL);
		}
	}
	if (argc > 2)
	{
		tab = test_argc_more(argc, argv);
		if (tab == NULL)
		{
			free(tab);
			return (NULL);
		}
	}
	return (tab);
}

int	check_args(int argc, char **argv, t_stack *lst)
{
	char	**tab;

	tab = check(argc, argv);
	if (tab == NULL)
		return (-1);
	if (argv[1][0] == '\0')
	{
		free(tab);
		return (-1);
	}
	fill_stack(tab, lst);
	if (tab != NULL)
	{
		ft_free(tab, ft_tablen(tab));
		return (1);
	}
	return (-1);
}

char	**test_argc_more(int argc, char **argv)
{
	char	**tab;
	char	**tmp;

	tab = NULL;
	tmp = NULL;
	tab = malloc(sizeof(char *) * (argc + 1));
	if (!tab)
		return (NULL);
	tmp = fill_tab(tab, &argv[1], argc);
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tab = tmp;
	tab[argc] = NULL;
	if (is_only_int(tab) != 0 || is_duplicate(tab) != 0)
	{
		ft_free(tab, ft_tablen(tab));
		return (NULL);
	}
	return (tmp);
}

int is_only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
}

