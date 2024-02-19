/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:20 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:31:02 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * print the string parsed from .cub file
*/
void	print_textures_str(t_textures textures)
{
	printf("\n----- TEXTURES STRINGS -----\n");
	if (textures.north.cardinal_str)
		printf("north == %s\n", textures.north.cardinal_str);
	if (textures.south.cardinal_str)
		printf("south == %s\n", textures.south.cardinal_str);
	if (textures.east.cardinal_str)
		printf("east == %s\n", textures.east.cardinal_str);
	if (textures.west.cardinal_str)
		printf("west == %s\n", textures.west.cardinal_str);
	if (textures.floor.rgb_str)
		printf("floor == %s\n", textures.floor.rgb_str);
	if (textures.ceiling.rgb_str)
		printf("ceiling == %s\n", textures.ceiling.rgb_str);
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
