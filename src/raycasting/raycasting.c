/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:59 by yallo             #+#    #+#             */
/*   Updated: 2024/02/28 14:14:01 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	vertical(t_map *map, float ray_angle)
{
	int mx,my,mp,size_map;
	float rx,ry,xo,yo;

	size_map = 0;
	float ntan = -tan(ray_angle);
	if (ray_angle > P2 && ray_angle < P3)
	{
		rx = (((int)map->player.x >> 6) << 6) - 0.0001;
		ry = (map->player.x - rx) * ntan + map->player.y;
		xo = -64;
		yo = -xo * ntan;
	}
	if (ray_angle < P2 || ray_angle > P3)
	{
		rx = (((int)map->player.x >> 6) << 6) + 64;
		ry = (map->player.x - rx) * ntan + map->player.y;
		xo = 64;
		yo = -xo * ntan;
	}
	if (ray_angle == 0 || ray_angle == PI)
	{
		rx = map->player.x;
		ry = map->player.y;
		size_map = map->nbr_line;
	}
	while (size_map < map->nbr_line)
	{
		mx = (int) (rx) >> 6;
		my = (int) (ry) >> 6;
		mp = my * map->nbr_line + mx;
		if (mx < 0)
			mx = 0;
		if (my < 0)
			my = 0;
		// printf("%d > 0 && %d < %d * %d && map[%d][%d] == %c\n", mp, mp, map->nbr_line, map->nbr_column, my, mx, map->str_rectangle[my][mx]);
		if (mp > 0 && mp < map->nbr_line * map->nbr_column && map->str_rectangle[my][mx] == '1')
			size_map = map->nbr_line;
		else
		{
			rx += xo;
			ry += yo;
			size_map += 1;
		}
	}
	t_point test = {rx, ry, 0xf0000CD};
	return (test);
}

t_point	horizontal(t_map *map, float ray_angle)
{
	int mx,my,mp,size_map;
	float rx,ry,xo,yo;

	size_map = 0;
	float atan = -1 / tan(ray_angle);
	if (ray_angle > PI)
	{
		ry = (((int)map->player.y >> 6) << 6) - 0.0001;
		rx = (map->player.y - ry) * atan + map->player.x;
		yo = -64;
		xo = -yo * atan;
	}
	if (ray_angle < PI)
	{
		ry = (((int)map->player.y >> 6) << 6) + 64;
		rx = (map->player.y - ry) * atan + map->player.x;
		// printf("(%d - %f) * %f + %d == %f\n", map->player.y, ry, atan, map->player.x, rx);
		yo = 64;
		xo = -yo * atan;
	}
	if (ray_angle == 0 || ray_angle == PI)
	{
		rx = map->player.x;
		ry = map->player.y;
		size_map = map->nbr_column;
	}
	while (size_map < map->nbr_column)
	{
		mx = (int) (rx) >> 6;		//Error --> mx cannot be negative
		my = (int) (ry) >> 6;
		mp = my * map->nbr_column + mx;
		if (mx < 0)					//Fix the
			mx = 0;					//error of mx / my
		if (my < 0)					//being negative but
			my = 0;					//not very good
		if (mp > 0 && mp < map->nbr_line * map->nbr_column && map->str_rectangle[my][mx] == '1')
			size_map = map->nbr_column;
		else
		{
			rx += xo;
			ry += yo;
			size_map += 1;
		}
	}
	t_point test = {rx, ry, 0xf1E90FF};
	return (test);
}

double	distance(t_point player, t_point p1, t_point p2)
{
	double l1;
	double l2;

	l1 = sqrt(pow(p1.x - player.x, 2) + pow(p1.y - player.y, 2));
	l2 = sqrt(pow(p2.x - player.x, 2) + pow(p2.y - player.y, 2));
	if (l1 < l2)
		return (l1);
	else
		return (l2);
}

t_point shorter(t_point player, t_point p1, t_point p2)
{
	double l1;
	double l2;

	l1 = sqrt(pow(p1.x - player.x, 2) + pow(p1.y - player.y, 2));
	l2 = sqrt(pow(p2.x - player.x, 2) + pow(p2.y - player.y, 2));
	if (l1 < l2)
		return (p1);
	else
		return (p2);
}

void raycasting(t_data *data)
{
	int r;
	float ray_angle;
	double shortest;
	t_point horizon;
	t_point vertic;
	t_point player = {data->map.player.x, data->map.player.y, 0xf000000};

	ray_angle = data->map.player.angle - 30 * RAD;
	for (r=0; r<1920;r++)
	{
		if (ray_angle < 0)
			ray_angle += PI2;
		if (ray_angle > PI2)
			ray_angle -= PI2;
		horizon = horizontal(&(data)->map, ray_angle);
		vertic = vertical(&(data)->map, ray_angle);

		t_point test = shorter(player, horizon, vertic);

		shortest = distance(player, horizon, vertic);
		float ca = data->map.player.angle - ray_angle;
		if (ca < 0)
			ca += PI2;
		if (ca > PI2)
			ca -= PI2;
		shortest = shortest * cos(ca);
		float lineH = (8 * SIZEX) / shortest;
		if (lineH > SIZEY)
			lineH = SIZEY;
		float lineO = SIZEY / 2 - lineH / 2;
		trace(&(data)->mlx.img, r, 0, r, lineO, 0xfFF0000);				//ceiling
		trace(&(data)->mlx.img, r, lineO, r, lineH + lineO, test.color);//wall
		trace(&(data)->mlx.img, r, lineH + lineO, r, SIZEY, 0xfFFA500); //floor
		ray_angle += RAD/32;
	}
}
