/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:12:25 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/29 16:02:57 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);
int		ft_assign_line(char **line, char **str, int fd, int ret);
int		ft_read_line(int fd, char *buff, char **str);

#endif
