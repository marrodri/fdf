/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:15:33 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/15 22:27:03 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (s == NULL)
		return (int)(NULL);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			word++;
		i++;
	}
	if (s[0] != '\0')
		word++;
	return (word);
}

static char		*ft_set_word(char *s, char c, int *i)
{
	char	*wrd;
	int		size;
	int		index;

	index = 0;
	size = ft_strlen(s);
	wrd = (char*)malloc(size * sizeof(char *));
	while (s[*i] != c && s[*i])
	{
		wrd[index] = s[*i];
		index++;
		*i += 1;
	}
	wrd[index] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (ft_strdup(wrd));
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**str;

	i = 0;
	j = 0;
	words = ft_word_count(s, c);
	if (s == NULL)
		return (NULL);
	str = (char**)malloc(words * sizeof(char**));
	if (str == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		str[j] = ft_set_word((char*)s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
