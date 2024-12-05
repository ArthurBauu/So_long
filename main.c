/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:22:19 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/02 19:20:12 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage ./so_long 'path_to.ber'");
        return (1);
    }
    so_long(argv[1]);
    return (0);
}


/*int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "So_long");

    mlx_hook(data.win, 2, 1L << 0, press_esc, &data);
    mlx_hook(data.win, 17, 0, clic_cross, &data);
    
    mlx_loop(data.mlx);
    return (0);
}*/
