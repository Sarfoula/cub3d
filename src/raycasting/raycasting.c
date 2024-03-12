/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:59 by yallo             #+#    #+#             */
/*   Updated: 2024/03/12 17:08:46 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray(t_ray *ray, t_player player, int x)
{
	ray->mapX = (int)player.posX;							//represents current pos
	ray->mapY = (int)player.posY;							//of ray in the map[][]
	ray->cameraX = 2 * x / (double)screenwidth - 1;					//X-coordinate represents on screen
	ray->rayDirY = player.dirY + player.planeY * ray->cameraX;				//ray = dir of vision + (camera plan * cameraX) --> rotate dir by certain angle
	ray->rayDirX = player.dirX + player.planeX * ray->cameraX;				//Vector direction of
	ray->deltaDistX = (ray->rayDirX == 0) ? 1e30 : fabs(1 / ray->rayDirX);		//Distance to next border-line
	ray->deltaDistY = (ray->rayDirY == 0) ? 1e30 : fabs(1 / ray->rayDirY);		//from a border-line
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player.posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player.posX) * ray->deltaDistX;	//mapX and posX are equals ???
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player.posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player.posY) * ray->deltaDistY;
	}
}

int raycast(t_data *data, t_ray *ray, int x)
{
	int		hit = 0; //was there a wall hit?
	int		lineHeight;

	init_ray(ray, data->player, x);
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (data->map.str_rectangle[ray->mapX][ray->mapY] == '1')
			hit = 1;
	}

	//Avoid fisheye effect
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);

	lineHeight = (int)(screenheight / ray->perpWallDist); //Relation further distance equals smaller in our vision (inversement egale)
	return (lineHeight);
}

void raycasting(t_data *data)
{
	int		lineHeight;
	int		color;
	int		cardinals;
	int		drawStart;
	int		drawEnd;
	t_ray	*ray;

	ray = &(data)->ray;
	for (int x = 0; x < screenwidth; x++)
	{
		lineHeight = raycast(data, ray, x);
		drawStart = screenheight / 2 - lineHeight / 2; //Centers in middle of screen the starting of wall
		if (drawStart < 0)
			drawStart = 0;
		else
			trace(data->mlx.img, x, 0, x, drawStart, data->map.textures.ceiling.color);
		drawEnd = screenheight / 2 + lineHeight / 2; //Centers in middle of screen the ending of wall
		if (drawEnd >= screenheight)
			drawEnd = screenheight - 1;
		else
			trace(data->mlx.img, x, drawEnd, x, screenheight, data->map.textures.floor.color);


		// int texNum = data->map.str_rectangle[ray->mapX][ray->mapY] - 1;	//tells which textures (in our it will be side NS EW)

		double wallX;							//Wich X was hit of the wall (X n'est pas ortho norme mais simplement le x de largeur mur)
		if (ray->side == 0)
		{
			cardinals = 1;
			wallX = data->player.posY + ray->perpWallDist * ray->rayDirY;
		}
		else
		{
			cardinals = 3;
			wallX = data->player.posX + ray->perpWallDist * ray->rayDirX;
		}
		wallX -= floor(wallX);
		int texX = (int)(wallX * (double)texWidth);		//X coordinate of the textures
		if (ray->side == 0 && ray->rayDirX > 0)
		{
			cardinals = 2;
			texX = texWidth - texX - 1;
		}
		if (ray->side == 1 && ray->rayDirY < 0)
		{
			cardinals = 4;
			texX = texWidth - texX - 1;
		}

		double step = 1.0 * texHeight / lineHeight;		//how much to increase the texture coordinate per screen pixel
		double texPos = (drawStart - screenheight / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y  < drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			if (cardinals == 1)
				color = data->map.textures.north.rgb[texY][texX];
			else if (cardinals == 2)
				color = data->map.textures.south.rgb[texY][texX];
			else if (cardinals == 3)
				color = data->map.textures.east.rgb[texY][texX];
			else
				color = data->map.textures.west.rgb[texY][texX];
			my_mlx_pixel_put(data->mlx.img, x, y, color);
		}
	}
}
