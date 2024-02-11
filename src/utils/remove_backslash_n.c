/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash_n.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:13:56 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/11 13:14:12 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Remove the first occurence of '\n'
*/
void	remove_backslash_n(char **str)
{
	int		i;
	int		j;
	int		flag;
	char	*temp;

	i = 0;
	while (str[i])
	{
		flag = 0;
		j = 0;
		while (str[i][j] && flag == 0)
		{
			if (str[i][j] == '\n')
			{
				str[i][j] = '\0';
				flag = 1;
			}
			j++;
		}
		i++;
	}
}
