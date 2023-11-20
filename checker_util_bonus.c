/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:51:14 by maricont          #+#    #+#             */
/*   Updated: 2023/10/09 10:01:10 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_duplicate_chk(t_Stack **stack)
{
	int		nro;
	t_Stack	*inter;
	t_Stack	*exter;

	exter = *stack;
	while (exter)
	{
		nro = exter->value;
		inter = exter->next_nodo;
		while (inter)
		{
			if (inter->value == nro)
				ft_error(stack);
			inter = inter->next_nodo;
		}
		exter = exter->next_nodo;
	}
	return (0);
}
