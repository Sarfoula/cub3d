/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/07 10:28:35 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_textures(t_map *map, t_textures *textures)
{
	free_xpm_rgb(textures);
	free_textures(textures);
	free_map(map);
}

int	next_frame(t_data *data)
{
	ft_memset(data->mlx.img.addr, 0, screenheight * data->mlx.img.line_len);
	raycasting(data);
	if (data->map.minimap == 1)
		minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_data		data;

	data.map.str = NULL;
	if (input_ok(argc, argv, &fd) == false)
		return (0);
	if (get_textures(fd, &(data).map.textures) == false)
		return (close(fd), 0);
	if (get_map(fd, &(data).map) == false)
		return (close(fd), free_textures(&(data).map.textures), 0);
	if (check_textures(&(data).map.textures) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	if (check_map(&(data).map, &(data).player) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	if (init_mlx(&data) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	// A EFFACER
	print_textures_str(data.map.textures);
	print_rgbs(data.map.textures);
	print_map(data.map, data.player);
	// A EFFACER
	mlx_hook(data.mlx.window, 2, 1, key_input, &data);
	mlx_hook(data.mlx.window, 17, 0, mlx_loop_end, data.mlx.mlx);
	mlx_loop_hook(data.mlx.mlx, next_frame, &data);
	mlx_loop(data.mlx.mlx);
	free_mlx(data.mlx);
	free_map_textures(&(data).map, &(data).map.textures);
	printf("no issue whatsoever\n");
}
