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

int	check_valid_file(const int fd, t_map **st_map, t_app **st_app)
{
	char *line;
	char *str_map;
	char *temp;
	char **splt_map;
	int count;

	if ((*st_map = malloc(sizeof(t_map))) == NULL)
		return (0);
	if((*st_app = malloc(sizeof(t_app))) == NULL)
		return (0);
	count = 0;
	(*st_map)->x = 0;
	(*st_map)->z = 0;
	str_map = ft_strnew(1);
	while(get_next_line(fd, &line))
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
	temp = str_map;
	str_map = ft_strtrim(str_map);
	splt_map = ft_strsplit(str_map, '\n');
	(*st_app)->vert_buff = setvert_buff(splt_map, *st_map, (*st_app)->vert_buff);
	free(temp);
	free(str_map);
	free(line);
	return (1);
}