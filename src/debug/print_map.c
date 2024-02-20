/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:47:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:44:21 by tbarde-c         ###   ########.fr       */
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
	ft_printf(1, "\n");
}
