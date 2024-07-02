/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:59:21 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:59:21 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	wordcount(const char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			inside_word = true;
			s++;
		}
		if (inside_word)
		{
			count++;
			inside_word = false;
		}
	}
	return (count);
}

char	*get_next_word(const char *s, char c, int *cursor)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (s[*cursor + len] != c && s[*cursor + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[*cursor] != c && s[*cursor] != '\0')
		word[i++] = s[(*cursor)++];
	word[i] = '\0';
	while (s[*cursor] == c && s[*cursor] != '\0')
		(*cursor)++;
	return (word);
}

char	**split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		word_count;
	int		cursor;

	i = 0;
	cursor = 0;
	word_count = wordcount(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	while (i < word_count)
	{
		tab[i] = get_next_word(s, c, &cursor);
		if (!tab[i])
		{
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
