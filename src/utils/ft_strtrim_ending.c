/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_ending.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:18:14 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 15:25:03 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	test(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_ending(char const *s1, char const *set)
{
	char	*ret;
	int		begin;
	int		i;
	int		end;

	begin = 0;
	i = 0;
	end = ft_strlen(s1);
	while (test(s1[end - 1], set) && end > begin)
		end--;
	ret = malloc(sizeof(*s1) *(end - begin + 1));
	if (!ret)
		return (0);
	while (end > begin)
	{
		ret[i] = s1[begin];
		i++;
		begin++;
	}
	ret[i] = 0;
	return (ret);
}

