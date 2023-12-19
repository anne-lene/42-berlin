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

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	char	c;

	nl = n;
	if (fd < 0)
		return ;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl = -nl;
	}
	if (n / 10 != 0)
		ft_putnbr_fd(nl / 10, fd);
	c = nl % 10 + '0';
	write(fd, &c, 1);
}
