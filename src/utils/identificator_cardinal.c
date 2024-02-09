/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identificator_cardinal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:25:38 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 20:29:28 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_north(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (true);
	return (false);
}

bool	is_south(char *str)
{
	if (str[i][0] == 'S' && str[i][1] == 'O')
		return (true);
	return (false);
}

bool	is_east(char *str)
{
	if (str[0] == 'E' && str[1] == 'A')
		return (true);
	return (false);
}
bool	is_west(char *str)
{
	if (str[0] == 'W' && str[1] == 'E')
		return (true);
	return (false);
}