/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:33:23 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/14 15:42:41 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	one_arg_only(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

static bool	file_is_dotcub(char *file)
{
	char	*dot;
	char	*cub;
	int		i;

	dot = ft_strchr(file, '.');
	if (!dot)
		return (false);
	if (ft_strlen(dot) != ft_strlen(".cub"))
		return (false);
	cub = ".cub";
	i = 0;
	while (dot[i])
	{
		if (dot[i] != cub[i])
			return (false);
		i++;
	}
	return (true);
}

/**
 * Check that input is valid
 * - 1 arg only
 * - file has append .cub
 * - file can be opened
*/
bool	input_ok(int argc, char **argv, int *fd)
{
	if (one_arg_only(argc) == false)
	{
		printf(INP_USAGE);
		return (false);
	}
	if (file_is_dotcub(argv[1]) == false)
	{
		printf(INP_FILENAME);
		return (false);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		ft_printf(2, "Error\nfile : '%s'\n", argv[1]);
		return (perror(ERR_OPEN), 0);
	}
	return (true);
}
