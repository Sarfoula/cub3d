/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:06:27 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:10:09 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", count, fd));
	while (s[i])
	{
		ft_putchar(s[i], count, fd);
		i++;
	}
}
