/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:45 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/13 12:52:50 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rgb(t_cardinal tex)
{
	int	i;

	i = 0;
	while (i < tex.width)
	{
		free(tex.rgb[i]);
		i++;
	}
	free(tex.rgb);
}

/**
 * Free the cardinal.rgb from textures
*/
void	free_xpm_rgb(t_textures *textures)
{
	free_rgb(textures->north);
	free_rgb(textures->south);
	free_rgb(textures->east);
	free_rgb(textures->west);
	get_next_line(-2);
}
