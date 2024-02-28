/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:47:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/27 16:16:53 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map map)
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
	ft_printf(1, "Spawn x location %d\n", map.player.x);
	ft_printf(1, "Spawn y location %d\n", map.player.y);
	ft_printf(1, "\n");
}
