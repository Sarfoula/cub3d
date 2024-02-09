/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identificator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:29:52 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 20:30:20 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_floor(char *str)
{
	if (str[0] == 'F')
		return (true);
	return (false);
}

bool	is_ceiling(char *str)
{
	if (str[0] == 'C')
		return (true);
	return (false);
}
