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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_handle_hex(char format, unsigned int num);
int	ft_print_char(int to_print);
int	ft_print_str(char *to_print);
int	ft_handle_ui(unsigned int to_print);
int	ft_handle_int(int to_print);
int	ft_handle_ptr(void *ptr);
#endif
