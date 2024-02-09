/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:06:15 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:10:03 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putchar(int c, int *count, int fd)
{
	if (*count == -1)
		return ;
	if (write(fd, &c, 1) == -1)
		*count = -1;
	else
		*count = *count + 1;
}
