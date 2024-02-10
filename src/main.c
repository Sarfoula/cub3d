/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 19:25:17 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_textures	textures;
	int			fd;

	if (input_ok(argc, argv) == false)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(ERR_OPEN), 0);
	(void)fd;
	if (get_textures(fd, &textures) == false)
		return (0);
	// A EFFACER
	print_textures(textures);
	// A EFFACER
	free_textures(&textures);
}
