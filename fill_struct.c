/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:41:29 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/08 19:24:25 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *str_nmap(t_map **map)
{
    char *str;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!map || !*map || !(*map)->txt || (*map)->col == 0 || (*map)->row == 0)
        return (NULL);
    str = (*map)->txt;
    (*map)->n_map = malloc(sizeof(char) * ((*map)->col * (*map)->row - (*map)->row + 1));
    if (!(*map)->n_map)
        return (NULL);
    while (str[i])
    {
        if (str[i] != '\n')
        {
            (*map)->n_map[j] = str[i];
            j++;
        }
        i++;
    }
    (*map)->n_map[j] = '\0';
    return ((*map)->n_map);
}



int count_all(t_map **map, char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '1')
            (*map)->wall_nb += 1;
        if (str[i] == 'c')
            (*map)->item_nb += 1;
        if (str[i] == 'm')
            (*map)->monster_nb += 1;
        if (str[i] == '0')
            (*map)->void_nb += 1;
        i++;
    }
    (*map)->wall_pos = malloc(sizeof(size_t) * ((*map)->wall_nb + 1));
    (*map)->item_pos = malloc(sizeof(size_t) * ((*map)->item_nb + 1));
    (*map)->monster_pos = malloc(sizeof(size_t) * ((*map)->monster_nb + 1));
    (*map)->void_pos = malloc(sizeof(size_t) * ((*map)->void_nb + 1));
    (*map)->player_pos = malloc(sizeof(size_t) * 1);
    (*map)->exit_pos = malloc(sizeof(size_t) * 1);
    if (!(*map)->wall_pos || !(*map)->item_pos || !(*map)->monster_pos || 
        !(*map)->void_pos || !(*map)->player_pos || !(*map)->exit_pos)
        return (-1);
    return (0);
}

int fill_pos(size_t **item, char *str, char c)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (str[i])    
    {
        if (str[i] == c)
        {
            (*item)[count] = i;
            count++;
        }
        i++;
    }
    return (0);
}



int struct_fill(t_map **map)
{
    char *str;

    str = str_nmap(map);
    if (count_all(map, str) != 0)
        return (-1);
    fill_pos(&(*map)->wall_pos, str,'1');
    fill_pos(&(*map)->void_pos, str, '0');
    fill_pos(&(*map)->item_pos, str,'c');
    fill_pos(&(*map)->monster_pos, str, 'm');
    fill_pos(&(*map)->player_pos, str,'p');
    fill_pos(&(*map)->exit_pos, str, 'e');
    // print_wall_pos(*map);
    // print_item_pos(*map);
    // printf("%ld\n", (*map)->player_pos[0]);
    // printf("%ld\n", (*map)->exit_pos[0]);
    return (0);
}







