/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:59 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/04 16:37:03 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    rgb_to_int(char *str)
{
    int red = 0, green = 0, blue = 0;
    int result;

    while (*str && *str != ',')
    {
        red = red * 10 + (*str - '0');
        str++;
    }
    str++;
    while (*str && *str != ',') {
        green = green * 10 + (*str - '0');
        str++;
    }
    str++;
    while (*str && *str != ',') {
        blue = blue * 10 + (*str - '0');
        str++;
    }
    result = (red << 16) | (green << 8) | blue;
    return (result);
}
