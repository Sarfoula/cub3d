/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:54:45 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_textures	textures;
	int			fd;
	t_map		map;

	map.str = NULL;
	if (input_ok(argc, argv, &fd) == false)
		return (0);
	if (get_textures(fd, &textures) == false)
		return (close(fd), 0);
	if (get_map(fd, &map) == false)
	{
		free_textures(&textures);
		return (0);
	}
	close(fd);
	if (check_textures(&textures) == false)
	{
		free_map(&map);
		free_textures(&textures);
		return (0);
	}
	if (check_map(&map) == false)
	{
		free_map(&map);
		free_textures(&textures);
		return (0);
	}
	// A EFFACER
	print_textures_str(textures);
	print_rgbs(textures);
	print_map(map);
	// A EFFACER
	free_textures(&textures);
	free_map(&map);
	printf("no issue whatsoever\n");
}
