/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 20:24:33 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check that we have one number for each rgb
 * @return true if we have one for each
 * @return else return false
*/
static bool	three_rgb_number(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (false);
	return (true);
}

/**
 * fill the rgb values in the t_rgb structure
 * then check if these values are valid (between 0 and 255)
 * @return true if the values are valid
 * @return false is the value are invalid
*/
static bool	fill_rgb_values(t_rgb *texture, char **rgb)
{
	texture->red = ft_atoi(rgb[0]);
	texture->green = ft_atoi(rgb[1]);
	texture->blue = ft_atoi(rgb[2]);
	//check that the input is less than an int ?
	if (texture->red > 255 || texture->green > 255 || texture->blue > 255)
		return (false);
	if (texture->red < 0 || texture->green < 0 || texture->blue < 0)
		return (false);
	return (true);
}

static bool	check_rgb(t_rgb *texture)
{
	int		i;
	char	**rgb;
	char	*str;

	str = texture->rgb_str;
	i = 2;
	while (ft_isspace(str[i]) == true)
		i++;
	rgb = ft_split(str + i, ',');
	if (three_rgb_number(rgb) == false)
	{
		ft_printf(2, ERR_RGB_NBR, str);
		free_split(rgb);
		return (false);
	}
	if (fill_rgb_values(texture, rgb) == false)
	{
		ft_printf(2, ERR_RGB_NBR, str);
		free_split(rgb);
		return (false);
	}
	free_split(rgb);
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
	//check filepath
	if (check_rgb(&textures->floor) == false || check_rgb(&textures->ceiling) == false)
		return (false);
	return (true);
}
