/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:16 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:18:44 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D__H
# define CUB3D__H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"

/**
 * ERROR MESSAGES
*/
# define INP_USAGE "[usage] : ./cub3d <file.cub>\n"
# define INP_FILENAME "File must be a .cub file\n"

# define ERR_FILEPATH_CONTENT "Error: there is no filepath in '%s'\n"

# define ERR_MAP_NULL "Error: there is no map\n"

# define ERR_OPEN "Couldn't open data file"

# define ERR_RGB_NBR "Error: RGB code is invalid in '%s'\n"

# define ERR_TEXTURES_NBR "Error: Cub3d couldn't get 6 ligns to read textures\n"
# define ERR_TEXTURES_CONTENT "Error: One of the six first ligns contains an unknown identifier or has a duplicate\n"
# define ERR_TEXTURES_XPM "Error: the file '%s' isn't a .xpm file\n"

/**
 * Textures structure
*/
typedef struct s_rgb
{
	char	*rgb_str;
	int		red;
	int		green;
	int		blue;
}	t_rgb;

typedef struct s_cardinal
{
	char	*cardinal_str;
	int		fd;
}	t_cardinal;

typedef struct s_textures
{
	t_cardinal	north;
	t_cardinal	south;
	t_cardinal	east;
	t_cardinal	west;
	t_rgb		floor;
	t_rgb		ceiling;
}	t_textures;

/********************************************************
					Debug
*********************************************************/
void	print_textures_str(t_textures textures);
void	print_rgbs(t_textures textures);

/********************************************************
					String Manipulation
*********************************************************/
bool	ft_isspace(char c);
bool	line_empty(char *line);
void	remove_backslash_n(char **str);
bool	ft_strstr_last(char *str, char *to_find);

/********************************************************
					Cleaning
*********************************************************/
void	free_textures(t_textures *textures);
void	free_split(char **rgb);
void	free_map(char **map);

/********************************************************
					Input checking
*********************************************************/
bool	input_ok(int argc, char **argv, int *fd);

/********************************************************
					Parsing
*********************************************************/
//	--- Textures ---
bool	get_textures(int fd, t_textures *textures);
bool	check_textures(t_textures *textures);
bool	check_filepath(t_cardinal *cardinal);
bool	check_rgb(t_rgb *texture);
bool	is_cardinal(char *str, char *cardinal);
bool	is_north(char *str);
bool	is_south(char *str);
bool	is_east(char *str);
bool	is_west(char *str);
bool	is_floor(char *str);
bool	is_ceiling(char *str);

//	---	Map	---
bool	get_map(int fd, char ***map);



#endif