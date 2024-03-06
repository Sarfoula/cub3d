/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:41:47 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/05 13:56:28 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_xpm_infos(t_cardinal xpm)
{
	ft_printf(1, "xpm width  = %d\n", xpm.width);
	ft_printf(1, "xpm height = %d\n", xpm.height);
	ft_printf(1, "xpm colors = %d\n", xpm.nb_of_colors);
}

void	print_color_table(t_color_table table)
{
	ft_printf(1, "--- color table char  = %c ---\n", table.c);
	ft_printf(1, "color table red   = %s %d\n", table.red_hex, table.red);
	ft_printf(1, "color table green = %s %d\n", table.green_hex, table.green);
	ft_printf(1, "color table blue  = %s %d\n", table.blue_hex, table.blue);
	ft_printf(1, "color table rgb   = %d\n", table.rgb);
}