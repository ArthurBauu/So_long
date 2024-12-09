/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:33:42 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/08 17:34:10 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_wall_pos(t_map *map)
{
    printf("Positions des murs (wall_pos):\n");
    for (size_t i = 0; i < map->wall_nb; i++)
    {
        printf("Mur %zu à la position: %zu\n", i + 1, map->wall_pos[i]);
    }
}

void print_item_pos(t_map *map)
{
    printf("Positions des items (item_pos):\n");
    for (size_t i = 0; i < map->item_nb; i++)
    {
        printf("item %zu à la position: %zu\n", i + 1, map->item_pos[i]);
    }
}