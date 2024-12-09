/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:24 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/06 23:43:22 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangle(t_map **map)
{
    char **tab;
    int i;

    if (!(*map)->txt)
        return (-1);
    i = 0;
    tab = ft_split((*map)->txt, '\n');
    if (!tab)
        return (-1);
    while (tab[i])
    {
        if (ft_strlen(tab[0]) != ft_strlen(tab[i]))
            return (-1);
        i++;
    }
    if (ft_strlen(tab[0]) == i || i <= 3 || ft_strlen(tab[0]) <= 3)
        return (-1);
    (*map)->col = ft_strlen(tab[0]);
    (*map)->row = i;
    ft_ffree(tab, (*map)->row);
    return (0);
}

int is_wall_ok(t_map **map)
{
    char **tab;
    size_t i; 
    size_t j;

    i = 0;
    j = 0; 
    tab = ft_split((*map)->txt, '\n');
    if (!tab)
        return (-1);
    while (j < (*map)->col)
    {
        if (tab[0][j] != '1' || tab[(*map)->row-1][j] != '1')
            return (-1);
        j++;
    }
    i = 0;
    while (i < (*map)->row)
    {
        if (tab[i][0] != '1' || tab[i][(*map)->col-1] != '1')
            return (-1);
        i++;
    }
    ft_ffree(tab, (*map)->row);
    return (0);
}

int elem_count(char **tab, int *p, int *c, int *e)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][0] == '\0')
            {
                ft_printf("Caractère invalide dans le format de la map");
                return (-1);
            }
            if (tab[i][j] == 'p')
                *p += 1;
            if (tab[i][j] == 'c')
                *c += 1;
            if (tab[i][j] == 'e')
                *e += 1;
            j++;
        }
        i++;       
    }
    return (0);
}

int is_elem_present(t_map **map)
{
    int p;
    int c;
    int e;
    char **tab;
    
    p = 0;
    c = 0;
    e = 0;
    tab = ft_split((*map)->txt, '\n');
    if (!tab || elem_count(tab, &p, &c, &e) != 0)
        return (-1);
    if ( p != 1 || e != 1 || c < 1)
    { 
        if (p != 1)
            ft_printf("Il ne peut y avoir qu'un seul joueur sur la carte");
        else if (c < 1)
            ft_printf("Il doit obligatoirement y avoir au moins un collectible");
        else if (e != 1)
            ft_printf("Il ne doit y avoir qu'une sortie");
        return (-1);
    }
    ft_ffree(tab, (*map)->row);
    return (0);
}

int is_carac_ok(t_map **map)
{
    int i;
    int j;
    char **tab;

    i = 0;
    tab = ft_split((*map)->txt, '\n');
    if (!tab)
        return (-1);
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != 'p' 
                && tab[i][j] != 'c' && tab[i][j] != 'e' && tab[i][j] != 'm')
            {    
                ft_printf("Caractère invalide dans le format de la map");
                return (-1);
            }
            j++;
        }
        i++;
    }
    ft_ffree(tab, (*map)->row);
    return (0);
}

// void split(t_map **map)
// {
//     int i;
//     char **tab;

//     i = 0;
//     tab = ft_split((*map)->txt, '\n');
//     while (tab[i])
//     {
//         ft_printf("%s\n", tab[i]);
//         i++;
//     }
// }