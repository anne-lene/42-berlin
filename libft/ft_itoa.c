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

static size_t	ft_ilen(long n)
{
	long	temp;
	size_t	count;

	temp = (long)n * ((long)n > 0) - (long)n * ((long)n < 0);
	count = (n <= 0);
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	temp;
	size_t	len;
	char	*s;

	len = ft_ilen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	temp = (long)n * ((long)n > 0) - (long)n * ((long)n < 0);
	while (temp != 0)
	{
		s[--len] = (temp % 10) + '0';
		temp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
