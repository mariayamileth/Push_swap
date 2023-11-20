/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:50:59 by maricont          #+#    #+#             */
/*   Updated: 2023/10/09 10:03:31 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char	*buffer_big, int i)
{
	char	*line;

	while (buffer_big[i] && buffer_big[i] != '\n')
		i++;
	if (buffer_big[i] == '\n')
	{
		line = malloc((i + 2) * sizeof(char));
		if (line)
			line[i + 1] = '\0';
	}
	else
	{
		line = malloc((i + 1) * sizeof(char));
		if (line)
			line[i] = '\n';
	}
	if (!line)
		return (NULL);
	while (i >= 0)
	{
		line[i] = buffer_big[i];
		i--;
	}
	return (line);
}

char	*ft_next(char	*buffer_big)
{
	int		i;
	char	*line;
	int		j;
	int		len;

	i = 0;
	while (buffer_big[i] && buffer_big[i] != '\n')
		i++;
	if (!buffer_big[i] || !buffer_big[i + 1])
		return (ft_free(&buffer_big));
	len = ft_strlen_bonus(buffer_big);
	line = (char *)malloc((len - i + 1) * sizeof(char));
	if (!line)
		return (ft_free(&buffer_big));
	j = 0;
	i++;
	while (buffer_big[i])
	{
		line[j] = buffer_big[i];
		i++;
		j++;
	}
	line[j] = '\0';
	ft_free(&buffer_big);
	return (line);
}

char	*ft_read_fd(int fd, char *buffer_big)
{
	int		len;
	char	buffer[BUFFER_SIZE + 1];

	len = 1;
	while (!ft_strchr_bonus(buffer_big, '\n') && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (ft_free(&buffer_big));
		if (len > 0)
		{
			buffer[len] = '\0';
			buffer_big = ft_strjoin(buffer_big, buffer);
			if (!buffer_big)
				return (ft_free(&buffer_big));
		}
	}
	return (buffer_big);
}

char	*get_next_line(int fd)
{
	static char	*buffer_big = NULL;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer_big = ft_read_fd(fd, buffer_big);
	if (!buffer_big)
		return (ft_free(&buffer_big));
	i = 0;
	line = ft_line(buffer_big, i);
	if (!line)
		return (ft_free(&buffer_big));
	buffer_big = ft_next(buffer_big);
	if (!buffer_big && !line)
		return (ft_free(&buffer_big));
	return (line);
}
