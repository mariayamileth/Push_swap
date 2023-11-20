/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:35:52 by maricont          #+#    #+#             */
/*   Updated: 2023/10/03 11:42:52 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_validate(t_Stack **stack)
{
	t_Stack	*temp;
	int		len;
	int		i;

	temp = *stack;
	len = ft_lstsize(*stack);
	i = 0;
	while (i < len - 1)
	{
		if (temp->index > temp->next_nodo->index)
			return (-1);
		temp = temp->next_nodo;
		i++;
	}
	return (0);
}

int	ft_max_index(t_Stack **stack)
{
	int		max;
	t_Stack	*temp;

	temp = (*stack);
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next_nodo;
	}
	return (max);
}

int	ft_position_index(t_Stack **stack, int index)
{
	int		pos;
	t_Stack	*temp;

	pos = 1;
	temp = *stack;
	while (temp)
	{
		if (temp->index == index)
			return (pos);
		temp = temp->next_nodo;
		pos++;
	}
	return (pos);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)s;
	while (dest[i] != '\0')
	{
		if (dest[i] == (char)c)
			return (&dest[i]);
		i++;
	}
	if ((char)c == '\0')
	{
		return (&dest[i]);
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
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
