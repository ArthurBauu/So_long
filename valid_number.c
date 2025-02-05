/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:33:38 by arbaudou          #+#    #+#             */
/*   Updated: 2025/01/10 16:50:11 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int		k;
	long	num;
	char	*strr;

	k = 0;
	if (str[k] == '-' || str[k] == '+')
		k++;
	while (str[k])
	{
		if ((str[k] < '0' || str[k] > '9'))
			return (-1);
		k++;
	}
	num = ft_atoi(str);
	strr = ft_itoa(num);
	if (is_valid_int(num) != 0 || ft_strcmp(str, strr) != 0)
	{
		free(strr);
		return (-1);
	}
	free(strr);
	return (0);
}

int	is_only_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_valid_number(str[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	is_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**test_argc_2(char *str)
{
	char	**tab;

	if (is_only_space(str) != 0)
	{
		return (NULL);
	}
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	if (is_only_int(tab) != 0 || is_duplicate(tab) != 0)
	{
		ft_free(tab, ft_tablen(tab));
		return (NULL);
	}
	return (tab);
}

char	**fill_tab(char **tab, char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
		if (!tab[i])
			return (NULL);
		while (argv[i][j])
		{
			tab[i][j] = argv[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
