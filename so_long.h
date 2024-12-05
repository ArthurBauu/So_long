/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:55 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/05 23:28:06 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 65307

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_data
{
    void *mlx;
    void *win;
}           t_data;

typedef struct s_map
{
    char    *txt;
    size_t  col;
    size_t  row;
    size_t  health;
    size_t  *player_pos;
    size_t  *exit_pos;
    size_t  *wall_pos;
    size_t *item_pos;
}           t_map;


void    press_esc(int key, t_data *data);
void    clic_cross(t_data *data);


t_map *init_map_struct(void);
char *read_ber(char *path);
short map_creation(char *map_path, t_map **map);

short so_long(char *map_path);

/*  PARSING  */
int is_rectangle(t_map **map);
int is_wall_ok(t_map **map);
int is_elem_present(t_map **map);
int is_carac_ok(t_map **map);



void split(t_map **map);

#endif