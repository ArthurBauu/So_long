/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:35:12 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/06 23:36:34 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map_struct(t_map *map)
{
    if (!map)
        return;
    if (map->txt)
        free(map->txt);
    if (map->n_map)
        free(map->n_map);
    if (map->player_pos)
        free(map->player_pos);
    if (map->exit_pos)
        free(map->exit_pos);
    if (map->wall_pos)
        free(map->wall_pos);
    if (map->item_pos)
        free(map->item_pos);
    if (map->monster_pos)
        free(map->monster_pos);
    free(map);
}
