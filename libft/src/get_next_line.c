/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:42:28 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/12 14:38:04 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Fill the buffer with what we had before and what we get next thanks to strjoin.
*/
static char	*fill_buffer(char *buffer, char *temp)
{
	char	*ret;

	ret = ft_strjoin(buffer, temp);
	free(buffer);
	return (ret);
}

/*
This function fills a buffer with the actual content of the file.
*/
static char	*read_file(char *buffer, int fd)
{
	char	*temp;
	int		byte_read;

	byte_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			free (buffer);
			return (0);
		}
		temp[byte_read] = '\0';
		buffer = fill_buffer(buffer, temp);
		if (ft_strchr_custom(temp, '\n') == 1)
			break ;
	}
	free(temp);
	return (buffer);
}

/*
Get the actual line that we will return in get_next_line,
which is the first line of the buffer we send.
*/
static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

/*
Modify the buffer to suppress the line we already processed
when the function is called multiple times,
which is always the first line.
*/
static char	*skip_line(char *buffer)
{
	int		i;
	int		j;
	char	*shorter_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (0);
	}
	shorter_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		shorter_buffer[j++] = buffer[i++];
	free(buffer);
	return (shorter_buffer);
}

/*
Core function.
*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -2)
		free(buffer);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = skip_line(buffer);
	return (line);
}
