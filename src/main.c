/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/14 12:18:55 by yallo            ###   ########.fr       */
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
	ft_memset(data->mlx.img.addr, 0, HEIGHT * data->mlx.img.line_len);
	raycasting(data, &(data)->ray);
	if (data->map.minimap == 1)
		minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, \
		data->mlx.img.img, 0, 0);
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
		return (free_textures(&(data).map.textures), close(fd), 0);
	if (check_textures(&(data).map.textures) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	if (check_map(&(data).map, &(data).player) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	if (init_mlx(&data) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	mlx_hook(data.mlx.window, 2, 1, key_input, &data);
	mlx_hook(data.mlx.window, 17, 0, mlx_loop_end, data.mlx.mlx);
	mlx_loop_hook(data.mlx.mlx, next_frame, &data);
	mlx_loop(data.mlx.mlx);
	free_mlx(data.mlx);
	free_map_textures(&(data).map, &(data).map.textures);
}
