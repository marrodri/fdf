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

int check_file(int fd, char **str_map)
{
    int is_valid;
    char *line;
    int count;
    int x;
    int z;

    count = 0;
    x = 0;
    z = 0;
    is_valid = 1;
    while(get_next_line(fd, &line) && is_valid)
    {
        count = ft_word_count(line, ' ');
        if(x == 0)
            x = count;
        if(count != x)
        {
            return 0;
        }
        z++;
    }
    printf("the map is x|%d| z|%d|\n", x, z);
    return (1);
}