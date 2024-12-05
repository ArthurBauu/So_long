/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:14:55 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/05 23:21:47 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(char **map, t_position pos, char target, char fill)
{
    if (map[pos.x][pos.y])
        return (-1);
    map[start.x][start.y] = fill;
    fill(map, (t_position){start.x + 1, start.y}, target, fill);
    fill(map, (t_position){start.x - 1, start.y}, target, fill);
    fill(map, (t_position){start.x, start.y + 1}, target, fill);
    fill(map, (t_position){start.x, start.y - 1}, target, fill); 
}

int flood_fill(char **map, t_position start, char target, char fill)
{
    if (!map || !map[start.x])
        return (-1);
    fill(map, start, target, fill);
    return (0);
}