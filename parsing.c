/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:49:23 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/08 18:15:42 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *init_map_struct(void)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return(NULL);
    map->txt = NULL;
    map->n_map = NULL;
    map->player_pos = NULL;
    map->exit_pos = NULL;
    map->wall_pos = NULL;
    map->item_pos = NULL;
    map->monster_pos = NULL;
    map->col = 0;
    map->row = 0;
    map->health = 3;
    map->wall_nb = 0;
    map->item_nb = 0;
    map->monster_nb = 0;
    map->exit_nb = 0;
    map->player_nb = 0;
    return (map);
}

char *read_ber(char *path)
{
	int		fd;
	char	*map_txt;
	char	*line;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_txt = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_txt, line);
		free(map_txt);
		free(line);
		map_txt = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
    //printf("%s", map_txt);
	return (map_txt);
}

short map_creation(char *map_path, t_map **map)
{
    *map = init_map_struct();
    (*map)->txt = read_ber(map_path);
    if (is_rectangle(map) != 0)
		return (ft_printf("La carte doit etre un rectangle"), 0);
	if (is_wall_ok(map) != 0)
		return (ft_printf("Il est necessaire que des murs encadre la map"));
	if (is_elem_present(map) != 0 || is_carac_ok(map) != 0)
		return (0);
	str_nmap(map);
	struct_fill(map);
	if (flood_fill(*map) == 0)
		ft_printf("SUCCES");
	//free_map_struct(*map);
	return (1);
}