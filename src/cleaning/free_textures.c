/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:07:19 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 16:28:05 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	free(textures->north.cardinal_str);
	free(textures->south.cardinal_str);
	free(textures->east.cardinal_str);
	free(textures->west.cardinal_str);
	free(textures->floor.rgb_str);
	free(textures->ceiling.rgb_str);
}
