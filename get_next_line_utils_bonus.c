/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:58:38 by maricont          #+#    #+#             */
/*   Updated: 2023/10/09 10:07:23 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(const char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

static char	*_ft_join_line(char *s1, char *s2, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen_bonus(s1))
	{
		dest[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen_bonus(s2))
	{
		dest [i + j] = ((char *)s2)[j];
		j++;
	}
	dest [i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (s1)
			s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (ft_free(&s1));
	dest = (char *)malloc((ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1)
			* sizeof(char));
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	dest = _ft_join_line(s1, s2, dest);
	free(s1);
	return (dest);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	if (s)
	{
		while (*s && (char)c != *s)
			s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}

void	*ft_free(char	**mem)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = NULL;
	}
	return (NULL);
}
