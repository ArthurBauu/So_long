/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:20:40 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/08 21:22:55 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short so_long(char *map_path)
{
    t_map *map;
    //t_mlx *mlx;

    if (map_creation(map_path, &map) != 0)
        return (EXIT_FAILURE);
    free_map_struct(map);
    return (1);
}