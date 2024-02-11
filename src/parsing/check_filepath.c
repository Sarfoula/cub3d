/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:07:01 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/11 13:01:26 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Remove the first two letters + space before the actual file path
 * If there is no path afterwards, return false
*/
static bool	remove_identifier(char **filepath)
{
	char	*temp;
	int		i;

	i = 2;
	temp = *filepath;
	while (ft_isspace((*filepath)[i]) == true)
		i++;
	if ((*filepath)[i] == '\0')
	{
		ft_printf(2, ERR_FILEPATH_CONTENT, *filepath);
		return (false);
	}
	*filepath = ft_strdup(*filepath + i);
	free(temp);
	return (true);
}



bool	check_filepath(t_cardinal *cardinal)
{
	if (remove_identifier(&cardinal->cardinal_str) == false)
	{
		return (false);
	}
	// if (get_check_fd(&cardinal) == false)
	// 	return (false);
	return (true);
}