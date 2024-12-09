/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:14:55 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/08 19:21:39 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t fill(char *map, size_t col, size_t start, size_t exit)
{
    if (start >= (size_t)ft_strlen(map))
        return 0;
    if (map[start] == '1' || map[start] == 'v')
        return 0;
    if (map[start] == 'e')
        return 1;
    map[start] = 'v';

    if (fill(map, col, start + 1, exit) == 1)
        return 1;
    if (fill(map, col, start - 1, exit) == 1)
        return 1;
    if (fill(map, col, start + col, exit) == 1)
        return 1;
    if (fill(map, col, start - col, exit) == 1)
        return 1;
    return 0;
}

static size_t fill_item(char *map, size_t col, size_t start)
{
    size_t nb_item = 0;

    if (start >= (size_t)ft_strlen(map))
        return 0;
    if (map[start] == '1' || map[start] == 'v')
        return 0;
    if (map[start] == 'c')
        nb_item = 1;
    map[start] = 'v';
    nb_item += fill_item(map, col, start + 1);
    nb_item += fill_item(map, col, start - 1);
    nb_item += fill_item(map, col, start + col);
    nb_item += fill_item(map, col, start - col);
    return (nb_item);
}



int flood_fill(t_map *map)
{
    char *temp;
    size_t len;
    size_t item;
    size_t exit;

    len = ft_strlen(map->n_map);
    temp = malloc(sizeof(char) * (len + 1));
    if (!temp)
        return (-1);
    ft_strlcpy(temp, map->n_map, len + 1);
    exit = fill(temp, map->col, map->player_pos[0], map->exit_pos[0]);
    free(temp);
    temp = malloc(sizeof(char) * (len + 1));
    if (!temp)
        return (-1);
    ft_strlcpy(temp, map->n_map, len + 1);
    item = fill_item(temp, map->col, map->player_pos[0]);
    if (exit == 1 && map->item_nb == item)
        return (0);
    return (-1);
}