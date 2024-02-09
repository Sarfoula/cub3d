/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:06:23 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:10:07 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *count, int fd)
{
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648", count, fd)); 
	if (nbr < 0)
	{
		ft_putchar('-', count, fd);
		nbr = -nbr;
	}
	ft_putnbr_base(nbr, "0123456789", count, fd);
}
