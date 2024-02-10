/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:20 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 20:23:58 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * print the string parsed from .cub file
*/
void	print_textures_str(t_textures textures)
{
	printf("\n----- TEXTURES STRINGS -----\n");
	if (textures.north)
		printf("north == %s", textures.north);
	if (textures.south)
		printf("south == %s", textures.south);
	if (textures.east)
		printf("east == %s", textures.east);
	if (textures.west)
		printf("west == %s", textures.west);
	if (textures.floor.rgb_str)
		printf("floor == %s", textures.floor.rgb_str);
	if (textures.ceiling.rgb_str)
		printf("ceiling == %s", textures.ceiling.rgb_str);
	printf("\n");
}

void	print_rgbs(t_textures textures)
{
	printf("\n----- RGB NUMBERS -----\n");
	printf("floor red == %d\n", textures.floor.red);
	printf("floor green == %d\n", textures.floor.green);
	printf("floor blue == %d\n", textures.floor.blue);
	printf("ceiling red == %d\n", textures.ceiling.red);
	printf("ceiling green == %d\n", textures.ceiling.green);
	printf("ceiling blue == %d\n", textures.ceiling.blue);
	printf("\n");
}