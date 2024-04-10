/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansax <ansax@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:27:53 by ansax             #+#    #+#             */
/*   Updated: 2024/04/05 09:28:07 by ansax            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uilen(unsigned int n)
{
	int	count;

	count = 1;
	n /= 10;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_uilen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int	ft_handle_ui(unsigned int to_print)
{
	char	*num;
	int		str_len;

	num = ft_uitoa(to_print);
	if (!num)
		return (-1);
	str_len = ft_print_str(num);
	free(num);
	if (str_len < 0)
		return (-1);
	return (str_len);
}
