/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansax <ansax@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:47:30 by ansax             #+#    #+#             */
/*   Updated: 2023/11/13 14:47:35 by ansax            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	word;

	word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && word != 1)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

size_t	count_letters(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

char	**ft_allocate_memory(char **arr, size_t idx, size_t count)
{
	arr[idx] = (char *)malloc((count + 1) * sizeof(char));
	if (!arr[idx])
	{
		while (idx > 0)
			free(arr[--idx]);
		free(arr);
		return (NULL);
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	letter_count;
	size_t	word_idx;
	char	**array;

	word_idx = 0;
	word_count = count_words(s, c);
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (word_idx < word_count)
	{
		while (*s == c)
			s++;
		letter_count = count_letters((char *)s, c);
		array = ft_allocate_memory(array, word_idx, letter_count);
		if (!array)
			return (NULL);
		ft_strlcpy(array[word_idx++], s, letter_count + 1);
		s += letter_count;
		while (*s == c && *s)
			s++;
	}
	array[word_count] = NULL;
	return (array);
}
