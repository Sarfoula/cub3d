/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:34 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_all_filepath(t_textures *textures)
{
	if (check_filepath(&textures->north) == false || \
	check_filepath(&textures->south) == false || \
	check_filepath(&textures->east) == false || \
	check_filepath(&textures->west) == false)
		return (false);
	return (true);
}

static bool	check_all_rgb(t_textures *textures)
{
	if (check_rgb(&textures->floor) == false || \
	check_rgb(&textures->ceiling) == false)
		return (false);
	return (true);
}

/**
 * Check the textures :
 * - for cardinal points, check if the filepath is correct
 * - for ceiling and floor, check if the rgb codes are valid
 * @return true if no issue was encoutered
 * @return false if a texture is invalid
*/
bool	check_textures(t_textures *textures)
{
	if (check_all_filepath(textures) == false)
		return (false);
	xpm_to_rgb(&textures->north);
	xpm_to_rgb(&textures->south);
	xpm_to_rgb(&textures->east);
	xpm_to_rgb(&textures->west);
	if (check_all_rgb(textures) == false)
		return (false);
	return (true);
}
