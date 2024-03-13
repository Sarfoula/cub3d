/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:02:01 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/13 13:37:16 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	has_non_numerical(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && ft_isspace(str[i]) == false)
			return (true);
		i++;
	}
	return (false);
}

/**
 * Check that we have one number for each rgb and no non-numerical char in them
 * @return true if we have one for each
 * @return else return false
*/
static bool	three_rgb_number(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (has_non_numerical(rgb[i]) == true)
			return (false);
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

/**
 * fill the rgb values in the t_rgb structure
 * then check if these values are valid (between 0 and 255)
 * We also add a strlen check so that we don't face issues with int overflows
 * @return true if the values are valid
 * @return false is the value are invalid
*/
static bool	fill_rgb_values(t_rgb *texture, char **rgb)
{
	texture->red = ft_atoi(rgb[0]);
	texture->green = ft_atoi(rgb[1]);
	texture->blue = ft_atoi(rgb[2]);
	if (ft_strlen(rgb[0]) >= 5 || ft_strlen(rgb[1]) >= 5 \
	|| ft_strlen(rgb[2]) >= 5)
		return (false);
	if (texture->red > 255 || texture->green > 255 || texture->blue > 255)
		return (false);
	if (texture->red < 0 || texture->green < 0 || texture->blue < 0)
		return (false);
	return (true);
}

/**
 * Check if an rgb is correct :
 * - We got 3 different rgb code numbers
 * - the values are correct (>= 0 && <= 255)
*/
bool	check_rgb(t_rgb *texture)
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
