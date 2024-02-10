/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:54:22 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 18:55:00 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check that the line is empty (only made of spaces or NULL)
 * If empty, return 
*/
bool	line_empty(char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (false);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (true);
	return (false);
}
