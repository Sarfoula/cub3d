/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:20 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 18:46:55 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_textures(t_textures textures)
{
	if (textures.north)
		printf("north == %s", textures.north);
	if (textures.south)
		printf("south == %s", textures.south);
	if (textures.east)
		printf("east == %s", textures.east);
	if (textures.west)
		printf("west == %s", textures.west);
	if (textures.floor)
		printf("floor == %s", textures.floor);
	if (textures.ceiling)
		printf("ceiling == %s", textures.ceiling);
}