/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:47:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:55:52 by tbarde-c         ###   ########.fr       */
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
		ft_printf(1, "%sspacescheck\n", map.str[i]);
		i++;
	}
	// ft_printf(1, "map nbr column %d\n", map.nbr_column);
	ft_printf(1, "map nbr line %d\n", map.nbr_line);
	ft_printf(1, "Spawn x location %d\n", map.spawn_x);
	ft_printf(1, "Spawn y location %d\n", map.spawn_y);
	ft_printf(1, "\n");
}
