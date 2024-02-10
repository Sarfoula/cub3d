/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:07:19 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 19:59:43 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	free(textures->north);
	free(textures->south);
	free(textures->east);
	free(textures->west);
	free(textures->floor.rgb_str);
	free(textures->ceiling.rgb_str);
}
