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

int	ft_print_str(char *to_print)
{
	int	str_len;
	int	written;

	if (to_print == NULL) 
	{
		written = write(1, "(null)", 6);
		if (written < 0)
			return (-1);
		return (6);
	}
	str_len = ft_strlen(to_print);
	written = write(1, to_print, str_len);
	if (written < 0)
		return (-1);
	return (str_len);
}
