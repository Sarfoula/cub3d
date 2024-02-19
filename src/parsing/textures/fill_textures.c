/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:32:08 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:44:17 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool fill_loop(t_textures *tex, char **tex_info, int *i)
{
	if (ft_strlen(tex_info[*i]) == 1)
		return (false);
	else if (tex->north.cardinal_str == NULL && is_north(tex_info[*i]))
		tex->north.cardinal_str = tex_info[*i];
	else if (tex->south.cardinal_str == NULL && is_south(tex_info[*i]))
		tex->south.cardinal_str = tex_info[*i];
	else if (tex->east.cardinal_str == NULL && is_east(tex_info[*i]))
		tex->east.cardinal_str = tex_info[*i];
	else if (tex->west.cardinal_str == NULL && is_west(tex_info[*i]))
		tex->west.cardinal_str = tex_info[*i];
	else if (tex->floor.rgb_str == NULL && is_floor(tex_info[*i]))
		tex->floor.rgb_str = tex_info[*i];
	else if (tex->ceiling.rgb_str == NULL && \
	is_ceiling(tex_info[*i]))
		tex->ceiling.rgb_str = tex_info[*i];
	else
		return (false);
	*i += 1;
	return (true);
}

/**
 * Check the identifier of the line and fill the t_textures struct
 * if we can't recognie the identifier, we return false
 * if we identified all 6 identifiers, we return true
*/
bool	fill_textures(t_textures *textures, char **textures_info)
{
	int	i;

	i = 0;
	while (textures_info[i])
	{
		if (fill_loop(textures, textures_info, &i) == false)
			return (false);
	}
	return (true);
}
/**
 * Check the identifier of the line and fill the t_textures struct
 * if we can't recognie the identifier, we return false
 * if we identified all 6 identifiers, we return true
*/
// bool	fill_textures(t_textures *textures, char **textures_info)
// {
// 	int	i;

// 	i = 0;
// 	while (textures_info[i])
// 	{
// 		if (ft_strlen(textures_info[i]) == 1)
// 			return (false);
// 		else if (textures->north.cardinal_str == NULL && is_north(textures_info[i]))
// 			textures->north.cardinal_str = textures_info[i];
// 		else if (textures->south.cardinal_str == NULL && is_south(textures_info[i]))
// 			textures->south.cardinal_str = textures_info[i];
// 		else if (textures->east.cardinal_str == NULL && is_east(textures_info[i]))
// 			textures->east.cardinal_str = textures_info[i];
// 		else if (textures->west.cardinal_str == NULL && is_west(textures_info[i]))
// 			textures->west.cardinal_str = textures_info[i];
// 		else if (textures->floor.rgb_str == NULL && is_floor(textures_info[i]))
// 			textures->floor.rgb_str = textures_info[i];
// 		else if (textures->ceiling.rgb_str == NULL && \
// 		is_ceiling(textures_info[i]))
// 			textures->ceiling.rgb_str = textures_info[i];
// 		else
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }
