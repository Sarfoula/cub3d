/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:24 by yallo             #+#    #+#             */
/*   Updated: 2024/03/04 17:25:47 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(char *str)
{
	int red = 0, green = 0, blue = 0;
	int result;

	while (*str && *str != ',')
	{
		red = red * 10 + (*str - '0');
		str++;
	}
	str++;
	while (*str && *str != ',') {
		green = green * 10 + (*str - '0');
		str++;
	}
	str++;
	while (*str && *str != ',') {
		blue = blue * 10 + (*str - '0');
		str++;
	}
	result = (red << 16) | (green << 8) | blue;
	return (result);
}

bool init_mlx(t_data *data)
{
	data->map.textures.ceiling.color = rgb_to_int(data->map.textures.ceiling.rgb_str);
	data->map.textures.floor.color = rgb_to_int(data->map.textures.floor.rgb_str);
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	data->mlx.window = mlx_new_window(data->mlx.mlx, screenwidth, screenheight, "cub3d");
	if (!data->mlx.window)
		return (false);
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, screenwidth, screenheight);
	if (!data->mlx.img.img)
		return (false);
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img, &data->mlx.img.bpp, \
		&data->mlx.img.line_len, &data->mlx.img.endian);
	for(int x = 0; x < texWidth; x++)
	for(int y = 0; y < texHeight; y++)
	{
		int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
		int ycolor = y * 256 / texHeight;
		int xycolor = y * 128 / texHeight + x * 128 / texWidth;
		data->textures[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
		data->textures[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
		data->textures[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
		data->textures[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
		data->textures[4][texWidth * y + x] = 256 * xorcolor; //xor green
		data->textures[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
		data->textures[6][texWidth * y + x] = 65536 * ycolor; //red gradient
		data->textures[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
	}
	return (true);
}

void free_mlx(t_mlx mlx)
{
	if (mlx.window)
		mlx_destroy_window(mlx.mlx, mlx.window);
	if (mlx.img.img)
		mlx_destroy_image(mlx.mlx, mlx.img.img);
	if (mlx.mlx)
	{
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
}
