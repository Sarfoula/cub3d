/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:33:23 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 19:24:18 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool one_arg_only(int argc)
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
*/
bool	input_ok(int argc, char **argv)
{
	if (one_arg_only(argc) == false)
	{
		ft_printf(1, ERR_USAGE);
		return (false);
	}
	if (file_is_dotcub(argv[1]) == false)
	{
		ft_printf(2, ERR_FILENAME);
		return (false);
	}
	return (true);
}
