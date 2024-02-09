/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:16 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 19:29:29 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D__H
# define CUB3D__H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"

/**
 * ERROR MESSAGES
*/
# define INP_USAGE "[usage] : ./cub3d <file.cub>\n"
# define INP_FILENAME "File must be a .cub file\n"

# define ERR_OPEN "Couldn't open data file"

/**
 * Textures structure
*/
typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
}	t_textures;

/**
 * Input checking
*/
bool	input_ok(int argc, char **argv);

#endif