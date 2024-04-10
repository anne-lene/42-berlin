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

static int	handle_format_specifier(const char **format, va_list *args)
{
	int	written;

	written = 0;
	if (**format == '%')
		written = write(1, *format, 1);
	else if (**format == 'c')
		written = ft_print_char(va_arg(*args, int));
	else if (**format == 's')
		written = ft_print_str(va_arg(*args, char *));
	else if (**format == 'd' || **format == 'i')
		written = ft_handle_int(va_arg(*args, int));
	else if (**format == 'u')
		written = ft_handle_ui(va_arg(*args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		written = ft_handle_hex(**format, va_arg(*args, unsigned int));
	else if (**format == 'p')
		written = ft_handle_ptr(va_arg(*args, void *));
	else 
		return (-1);
	if (written != -1)
		(*format)++;
	return (written);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;	
	int		written;

	count = 0;
	va_start(args, format);
	while (*format != '\0') 
	{
		if (*format == '%') 
		{
			format++;
			written = handle_format_specifier(&format, &args);
			if (written < 0)
				return (-1);
		}
		else 
		{
			written = write(1, format++, 1);
			if (written < 0)
				return (-1);
		}
		count += written;
	}
	va_end(args);
	return (count);
}
