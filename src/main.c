/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:40 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/28 13:13:49 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void square(t_image *img, int sizex, int sizey, int x, int y, int color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + sizex)
	{
		j = y;
		while (j < y + sizey)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_map(t_data *data)
{
	for (int i = 0; i < data->map.nbr_line; i++)
	{
		for (int j = 0; j < data->map.nbr_column; j++)
		{
			if (data->map.str_rectangle[i][j] == '1')
				square(&(data)->mlx.img, 63, 63, j * 64, i * 64, 0xfFFFFFF);
			else
				square(&(data)->mlx.img, 63, 63, j * 64, i * 64, 0xf000000);
		}
	}
}

void draw_player(t_data *data)
{
	square(&(data)->mlx.img, 11, 11, data->map.player.x - 5, data->map.player.y - 5, 0xf8B4513);
}

void	free_map_textures(t_map *map, t_textures *textures)
{
	free_textures(textures);
	free_map(map);
}

int	next_frame(t_data *data)
{
	ft_memset(data->mlx.img.addr, 0, SIZEY * data->mlx.img.line_len);
	// square(&(data)->mlx.img, SIZEX, SIZEY, 0, 0, 0xf808080);
	// draw_map(data);
	// draw_player(data);
	raycasting(data);
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
	if (check_map(&(data).map) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	if (init_mlx(&data) == false)
		return (free_map_textures(&(data).map, &(data).map.textures), 0);
	// A EFFACER
	print_textures_str(data.map.textures);
	print_rgbs(data.map.textures);
	print_map(data.map);
	// A EFFACER
	mlx_hook(data.mlx.window, 2, 1, key_input, &data.mlx);
	mlx_hook(data.mlx.window, 17, 0, mlx_loop_end, data.mlx.mlx);
	mlx_loop_hook(data.mlx.mlx, next_frame, &data);
	mlx_loop(data.mlx.mlx);
	free_map_textures(&(data).map, &(data).map.textures);
	printf("no issue whatsoever\n");
}
