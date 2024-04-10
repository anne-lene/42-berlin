/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansax <ansax@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:27:53 by ansax             #+#    #+#             */
/*   Updated: 2024/04/05 10:28:47 by ansax            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitohex(uintptr_t num)
{
	char			*str;
	int				len;
	uintptr_t		cpy;

	cpy = (uintptr_t)(num / 16);
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

int	ft_handle_ptr(void *ptr)
{
	char	*str;
	int		str_len;
	int		written;

	if (!ptr)
	{
		written = write(1, "(nil)", 5);
		if (written < 0)
			return (-1);
		return (written);
	}
	str = ft_uitohex((uintptr_t)ptr);
	if (!str)
		return (-1);
	written = write(1, "0x", 2);
	if (written < 0)
	{
		free(str);
		return (-1);
	}
	str_len = ft_print_str(str);
	free(str);
	if (str_len < 0)
		return (-1);
	return (str_len + 2);
}
