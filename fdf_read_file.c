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

void	free_doublestr(char **splt_map, int size)
{
	int i;

	i = 0;
	if (splt_map)
	{
		while (i < size)
		{
			free(splt_map[i]);
			i++;
		}
	}
	free(splt_map);
	return ;
}

char	*file_to_str(t_map **st_map, char *str_map, int fd)
{
	char	*line;
	char	*temp;
	int		count;

	count = 0;
	str_map = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		count = ft_word_count(line, ' ');
		if ((*st_map)->x == 0)
			(*st_map)->x = count;
		if (count != (*st_map)->x)
			return (0);
		temp = str_map;
		str_map = ft_strjoin(str_map, line);
		free(temp);
		free(line);
		temp = str_map;
		str_map = ft_strjoin(str_map, "\n");
		free(temp);
		(*st_map)->z++;
	}
	return (str_map);
}

int		check_valid_file(const int fd, t_map **st_map, t_app **st_app)
{
	char	*str_map;
	char	**splt_map;
	char	*temp;
	int		z;
	t_vert	*vert_buff;

	if ((*st_map = malloc(sizeof(t_map))) == NULL)
		return (0);
	if ((*st_app = malloc(sizeof(t_app))) == NULL)
		return (0);
	(*st_map)->x = 0;
	(*st_map)->z = 0;
	vert_buff = (*st_app)->vert_buff;
	str_map = file_to_str(&(*st_map), str_map, fd);
	temp = str_map;
	str_map = ft_strtrim(str_map);
	splt_map = ft_strsplit(str_map, '\n');
	(*st_app)->vert_buff = vert_buff_malloc(splt_map, *st_map, vert_buff);
	free(temp);
	free(str_map);
	free_doublestr(splt_map, (*st_map)->z - 1);
	return (1);
}
