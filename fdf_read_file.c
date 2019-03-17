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

int **assign_map(int **map, char **str_map)
{
	int x;
	int y;
	int i;

	y = 0;
	while (map[y])
	{
		x = 0;
		i = 0;
		while (str_map[y][i])
		{
			if (str_map[y][i] != ' '  && str_map[y][i])
			{
				// printf("x is %d\n",x);
				if(i == 0)
				{
					// printf("i is 0\n");
					map[y][x] = ft_atoi(&str_map[y][i]);
					x++;
				}
				else if (str_map[y][i - 1] == ' ')
				{
					// printf("there a space behind before str[%d][%d]\n", y, i);
					// printf("remaining string |%s|\n", &str_map[y][i]);
					// printf("atoi is |%d|\n", ft_atoi(&str_map[y][i]));
					map[y][x] = ft_atoi(&str_map[y][i]);
					x++;
				}
			}
			i++;
		}
		y++;
	}
	return (map);
}

int **create_map(int **map, int y, int x)
{
	int i;

	i = 0;
	// printf("x|%d|, y|%d|\n", x, y);
	if ((map = (int **)malloc((y + 1) * sizeof(int *))) == NULL)
		return (NULL);
	// printf("malloc y ready\n");
	while (i < y)
	{
		// printf("allocating %d line\n", i);
		if ((map[i] = (int *)malloc((x + 1) * sizeof(int))) == NULL)
			return (NULL);
		i++;
	}
	map[y] = NULL;
	i = 0;
	while(map[i])
	{
		map[i][x] = (int)NULL;
		i++;
	}
	// printf("map FULLY CREATED y|%d| x|%d|!!!\n", y, x);
	// printf("--- EXIT MAP CREATOR ---\n");
	return (map);
}

int check_valid_file(const int fd, t_map **st_map)
{
	char *line;
	char *str_map;
	char *temp;
	char **splt_map;
	int count;

	if ((*st_map = malloc(sizeof(t_map))) == NULL)
		return (0);

	count = 0;
	(*st_map)->x = 0;
	(*st_map)->y = 0;
	str_map = ft_strnew(1);
	while(get_next_line(fd, &line))
	{
		count = ft_word_count(line, ' ');
		if ((*st_map)->x == 0)
			(*st_map)->x = count;
		if (count != (*st_map)->x)
			return 0;
		temp = str_map;
		str_map = ft_strjoin(str_map, line);
		free(temp);
		free(line);
		temp = str_map;
		str_map = ft_strjoin(str_map, "\n");
		free(temp);
		(*st_map)->y++;
	}

	temp = str_map;
	str_map = ft_strtrim(str_map);
	// printf("%s\n",str_map);
	splt_map = ft_strsplit(str_map, '\n');
	(*st_map)->map = create_map((*st_map)->map, (*st_map)->y, (*st_map)->x);
	(*st_map)->map = assign_map((*st_map)->map, splt_map);
	free(temp);
	free(str_map);
	// printf("--- exitng check_valid_file and freeing unecesary file ---\n");
	return (1);
}