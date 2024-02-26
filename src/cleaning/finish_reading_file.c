/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_reading_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:06:27 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/26 14:55:55 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Read the file to the end with get_next_line to prevent still reachable leaks
 * @return true if the file still contained non empty lines
*/
bool	finish_reading_file(int fd)
{
	char	*line;
	bool	error;

	error = false;
	line = get_next_line(fd);
	while (line)
	{
		if (line_empty(line) == false)
			error = true;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (error == true)
		ft_printf(2, ERR_MAP_EMPTY);
	return (error);
}
