/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:11:21 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/02 19:26:16 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    press_esc(int key, t_data *data)
{
    if (key == ESC_KEY)
        {
            mlx_destroy_window(data->mlx, data->win);
            exit (0);
        }
    return ;
}

void    clic_cross(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return ;
}