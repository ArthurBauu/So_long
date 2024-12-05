/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:54:03 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/05 20:21:19 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gfree(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (buffer)
		free (buffer);
	return (temp);
}

char	*ft_next(char *buff)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	l = ft_calloc((ft_strglen(buff) - i), sizeof(char));
	if (!l)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		l[j++] = buff[i++];
	free(buff);
	return (l);
}

char	*ft_line(char *buff)
{
	char	*l;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	l = ft_calloc(i + 2, sizeof(char));
	if (!l)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		l[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		l[i++] = '\n';
	return (l);
}

char	*readf(int fd, char *res)
{
	char	*buff;
	int		b_read;

	if (!res)
		res = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(res);
			free(buff);
			return (NULL);
		}
		buff[b_read] = '\0';
		res = ft_gfree(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	str = readf(fd, str);
	if (!str || str == NULL)
		return (NULL);
	out = ft_line(str);
	str = ft_next(str);
	return (out);
}

/*
#include <fcntl.h>
int main() {
    int fd1, fd2, fd3;
    char *line;

    // Ouvrir les fichiers en mode lecture
    fd1 = 0;
    if (fd1 < 0) {
        perror("Erreur d'ouverture du fichier file");
        return 1;
    }

    // fd2 = open("file2.txt", O_RDONLY);
    // if (fd2 < 0) {
    //     perror("Erreur d'ouverture du fichier file2");
    //     close(fd1); // Fermer fd1 avant de quitter
    //     return 1;
    // }
    // fd3 = open("file3.txt", O_RDONLY);
    // if (fd3 < 0) {
    //     perror("Erreur d'ouverture du fichier file3");
    //     close(fd1);
    //     close(fd2);
    //     return 1;
    // }
    // Lire et afficher les lignes de chaque fichier
    printf("Lecture du fichier file:\n");
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line); // Libérer la mémoire allouée pour chaque ligne
    }
    close(fd1); // Fermer le fichier

    // printf("\nLecture du fichier file2:\n");
    // while ((line = get_next_line(fd2)) != NULL) {
    //     printf("%s", line);
    //     free(line); // Libérer la mémoire allouée pour chaque ligne
    // }
    // close(fd2); // Fermer le fichier

    // printf("\nLecture du fichier file3:\n");
    // while ((line = get_next_line(fd3)) != NULL) {
    //     printf("%s", line);
    //     free(line); // Libérer la mémoire allouée pour chaque ligne
    // }
    // close(fd3); // Fermer le fichier

    return 0;
}
*/

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

Déclarez ici vos fonctions auxiliaires 
(ft_calloc, ft_strjoin, ft_strlen, etc.)

int main(void)
{
    char *line;
    int fd = 0; // File descriptor 0 pour lire depuis stdin (entrée standard)

    // Boucle pour lire et afficher chaque ligne
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("rien a lire");
		if (line)
        {
            printf("Ligne lue : %s", line);  // Affiche la ligne lue
            free(line);  // Libère la mémoire de la ligne lue
        }
		else 
			printf("rien a lire");
    }
    //printf("rien a lire");
	return 0;
}
*/