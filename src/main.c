/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/14 12:59:49 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_textures	textures;
	int			fd;

	if (input_ok(argc, argv, &fd) == false)
		return (0);
	if (get_textures(fd, &textures) == false)
		return (0);
	//get_map
	close(fd);
	if (check_textures(&textures) == false)
	{
		free_textures(&textures);
		return (0);
	}
	// A EFFACER
	print_textures_str(textures);
	print_rgbs(textures);
	// A EFFACER
	free_textures(&textures);
	printf("no issue whatsoever\n");
}
