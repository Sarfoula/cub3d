/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:59 by yallo             #+#    #+#             */
/*   Updated: 2024/03/14 12:37:20 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_player player, int x)
{
	ray->mapx = (int)player.posx;
	ray->mapy = (int)player.posy;
	ray->camerax = 2 * x / (double)WIDTH - 1;
	ray->raydiry = player.diry + player.planey * ray->camerax;
	ray->raydirx = player.dirx + player.planex * ray->camerax;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->sidedistx = (ray->mapx + 1.0 - player.posx) * ray->deltadistx;
	ray->stepx = 1;
	if (ray->raydirx == 0)
		ray->deltadistx = 1e30;
	if (ray->raydiry == 0)
		ray->deltadisty = 1e30;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player.posx - ray->mapx) * ray->deltadistx;
	}
	ray->stepy = 1;
	ray->sidedisty = (ray->mapy + 1.0 - player.posy) * ray->deltadisty;
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player.posy - ray->mapy) * ray->deltadisty;
	}
}

int	raycast(t_data *data, t_ray *ray, int x)
{
	init_ray(ray, data->player, x);
	while (1)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (data->map.str_rectangle[ray->mapx][ray->mapy] == '1')
			break ;
	}
	if (ray->side == 0)
		ray->perpwalldist = ray->sidedistx - ray->deltadistx;
	else
		ray->perpwalldist = ray->sidedisty - ray->deltadisty;
	return ((int)(HEIGHT / ray->perpwalldist));
}

int	test(t_data *data)
{
	double	texx;
	double	wallx;

	data->ray.color = 3;
	wallx = data->player.posx + data->ray.perpwalldist * data->ray.raydirx;
	if (data->ray.side == 0)
	{
		data->ray.color = 1;
		wallx = data->player.posy + data->ray.perpwalldist * data->ray.raydiry;
	}
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)TEXWIDTH);
	if (data->ray.side == 0 && data->ray.raydirx > 0)
	{
		data->ray.color = 2;
		texx = TEXWIDTH - texx - 1;
	}
	if (data->ray.side == 1 && data->ray.raydiry < 0)
	{
		data->ray.color = 4;
		texx = TEXWIDTH - texx - 1;
	}
	return (texx);
}

int	textures(t_data *data, double *texpos, double step)
{
	int	texx;
	int	texy;

	texx = test(data);
	texy = (int)*texpos & (TEXHEIGHT - 1);
	*texpos += step;
	if (data->ray.color == 1)
		return (data->map.textures.north.rgb[texy][texx]);
	else if (data->ray.color == 2)
		return (data->map.textures.south.rgb[texy][texx]);
	else if (data->ray.color == 3)
		return (data->map.textures.east.rgb[texy][texx]);
	else
		return (data->map.textures.west.rgb[texy][texx]);
}

void	raycasting(t_data *data, t_ray *ray)
{
	int		x;
	int		y;
	double	step;
	double	texpos;

	x = -1;
	while (x++ < WIDTH)
	{
		ray->lineheight = raycast(data, ray, x);
		ray->drawstart = HEIGHT / 2 - ray->lineheight / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		else
			trace(data, x, 0, ray->drawstart);
		ray->drawend = HEIGHT / 2 + ray->lineheight / 2;
		if (ray->drawend >= HEIGHT)
			ray->drawend = HEIGHT - 1;
		else
			trace(data, x, ray->drawend, HEIGHT);
		step = 1.0 * TEXHEIGHT / ray->lineheight;
		texpos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2) * step;
		y = ray->drawstart - 1;
		while (y++ < ray->drawend)
			my_pixel_put(data->mlx.img, x, y, textures(data, &texpos, step));
	}
}
