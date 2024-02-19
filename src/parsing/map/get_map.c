/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:17:35 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:26:40 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line_empty(line) == true && line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

/**
 * Copy each line from the File to the char ***
*/
static void	copy_map_lines(char ***temp, char *line, int *i, int fd)
{
	while (line_empty(line) == false && line)
	{
		*temp[0] = ft_strdup(line);
		*temp = *temp + 1;
		free(line);
		line = get_next_line(fd);
		*i += 1;
	}
}

bool	get_map(int fd, char ***map)
{
	char	*line;
	int		i;
	char	**temp;

	temp = malloc(sizeof(char *));
	*map = temp;
	line = skip_empty_lines(fd);
	i = 0;
	copy_map_lines(&temp, line, &i, fd);
	if (i == 0)
	{
		ft_printf(2, ERR_MAP_NULL);
		free(temp);
		return (false);
	}
	else
		temp[i] = NULL;
	return (true);
}
