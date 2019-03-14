/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:32:59 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/09 21:33:02 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <stdio.h>

char ***create_map(char **str_spltd)
{
	char ***map;
	int y;
	int x;
	int i;
	int lines;
	
	i = 0;
	x = 0;
	y = 0;
	lines = 0;

	while (str_spltd[lines] != NULL)
		lines++;

	if ((map = (char ***)malloc((lines + 1) * sizeof(char **))) == NULL)
		return (NULL);
	
	while (str_spltd[i] != NULL)
	{
		map[i] = ft_strsplit(str_spltd[i], ' ');
		i++;
	}
	map[lines] = NULL;
	return (map);
}

// char **assign_map(const int fd)
// {
//     char    **tmp;
//     char    *str;
//     int     ret;
//     int     size;
//     char buff[BUFF_SIZE + 1];

//     size = 0;
//     while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
//     {
//         buff[ret] = '\0';
//         size = size + ret;
//         printf("ret |%d| size|%d|\n", ret, size);
//     }
//     printf("size of map is |%d|\n", size);
//     return (NULL);
// }

int check_valid_file(const int fd, t_map *map)
{
    char *line;
    char *str_map;
    int count;
    int x;
    int y;

    count = 0;
    x = 0;
    y= 0;
    str_map = ft_strnew(1);
    while(get_next_line(fd, &line))
    {
        count = ft_word_count(line, ' ');
        if (x == 0)
            x = count;
        if (count != x)
        {
            // printf("error, x is |%d| and count is |%d|\n",x, count);
            return 0;
        }
        str_map = ft_strjoin(str_map, line);
        str_map = ft_strjoin(str_map, "\n");
        y++;
    }
    str_map = ft_strtrim(str_map);
    count = ft_strlen(str_map);
    printf("count |%d|\n", count);
    free(line);
    printf("the map size x|%d| y|%d|\n", x, y);
    printf("and map is:\n%s\n", str_map);
    //str_map = assign_map(fd);
    // for(int i = 0; str_map[i] != NULL; i++)
    // {
    //     printf("string %d is |%s|", i, str_map[i]);
    // }
    printf("+++EXIT CHECK_VALID_FILE+++\n");
    return (1);
}