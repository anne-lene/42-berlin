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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n < 1)
		return (0);
	i = 0;
	while ((i < n - 1) && (s1[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
