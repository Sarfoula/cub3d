/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:08:01 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:08:08 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(int fd, const char *format, ...);
void	ft_putchar(int c, int *count, int fd);
void	ft_putnbr_base(long long unsigned int nbr, \
char *base, int *count, int fd);
void	ft_putnbr(int nbr, int *count, int fd);
void	ft_putstr(char *s, int *count, int fd);

#endif
