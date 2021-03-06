/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:56:52 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 21:24:07 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (void)(NULL);
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	s[i] = '\0';
}
