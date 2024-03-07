/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:47:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:58:37 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map map, t_player player)
{
	int	i;

	i = 0;
	ft_printf(1, "----- MAP -----\n");
	while (map.str[i])
	{
		ft_printf(1, "%s/END/\n", map.str[i]);
		i++;
	}
	ft_printf(1, "\n");
	i = 0;
	ft_printf(1, "----- RECTANGULAR MAP -----\n");
	while (map.str[i])
	{
		ft_printf(1, "%s\n", map.str_rectangle[i]);
		i++;
	}
	ft_printf(1, "\n");
	ft_printf(1, "map nbr column %d\n", map.nbr_column);
	ft_printf(1, "map nbr line %d\n", map.nbr_line);
	ft_printf(1, "Spawn x location %d\n", player.posX);
	ft_printf(1, "Spawn y location %d\n", player.posY);
	ft_printf(1, "\n");
}
