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

static char	*ft_uitohex(unsigned long long num)
{
	char	*str;
	int		len;
	int		cpy;

	cpy = (unsigned long long)(num / 16);
	len = 1;
	while (cpy)
	{
		cpy /= 16;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		cpy = num % 16;
		if (cpy > 9)
			str[--len] = cpy + 'a' - 10;
		else 
			str[--len] = cpy + '0';
		num /= 16;
	}
	return (str);
}

static void	ft_str_toupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	ft_handle_hex(char format, unsigned int num)
{
	char	*str_hex;
	int		str_len;

	str_hex = ft_uitohex((unsigned long long)num);
	if (!str_hex)
		return (-1);
	if (format == 'X')
		ft_str_toupper(str_hex);
	str_len = ft_print_str(str_hex);
	free(str_hex);
	if (str_len < 0)
		return (-1);
	return (str_len);
}
