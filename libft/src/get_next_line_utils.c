/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:27:09 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 18:27:19 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_custom(const char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}
