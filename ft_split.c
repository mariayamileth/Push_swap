/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:22:01 by maricont          #+#    #+#             */
/*   Updated: 2023/10/04 13:05:10 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	if (i > 0 && str[i - 1] != c)
		n++;
	return (n);
}

static char	*ft_malloc_word(char **dest, int n, int j)
{
	char	*dest2;

	dest2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest2)
	{
		while (j > 0)
		{
			j--;
			free(dest[j]);
		}
		free(dest);
		return (NULL);
	}
	dest2[n] = '\0';
	return (dest2);
}

static char	*ft_copy(char *dest2, char *str, char c, int i)
{
	int		k;

	k = 0;
	while (str[i] && str[i] != c)
		dest2[k++] = str[i++];
	return (dest2);
}

static char	**ft_list(char *str, char c, char **dest, int j)
{
	int		i;
	int		n;
	char	*dest2;

	i = 0;
	while (j < count_word(str, c))
	{
		n = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] && str[i] != c)
		{
			n++;
			i++;
		}
		dest2 = ft_malloc_word(dest, n, j);
		if (!dest2)
			return (NULL);
		i = i - n;
		dest[j] = ft_copy(dest2, str, c, i);
		i = i + ft_strlen(dest[j]);
		j++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**dest;
	int		j;
	int		n;
	int		cont;

	j = 0;
	n = 0;
	if (!s)
		return (0);
	str = (char *)s;
	n = count_word(str, c);
	dest = (char **)malloc((n + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[n] = NULL;
	cont = 0;
	return (ft_list(str, c, dest, j));
}
