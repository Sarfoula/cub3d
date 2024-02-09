/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:06:18 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:10:06 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long long unsigned int nbr, \
char *base, int *count, int fd)
{
	int	size;

	size = ft_strlen(base);
	if ((int)nbr > (size - 1))
		ft_putnbr_base((nbr / size), base, count, fd);
	ft_putchar(base[nbr % size], count, fd);
}
