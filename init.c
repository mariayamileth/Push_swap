/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:19:37 by maricont          #+#    #+#             */
/*   Updated: 2023/10/03 11:07:11 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_Stack **stack)
{
	t_Stack	*temp;

	temp = *stack;
	if (stack)
	{
		while (temp)
		{
			free(temp);
			temp = temp->next_nodo;
		}
		free(stack);
	}
}

static t_Stack	*ft_min(t_Stack **stack)
{
	t_Stack	*temp;
	t_Stack	*min_nodo;
	int		aux;

	temp = *stack;
	min_nodo = temp;
	aux = 0;
	while (temp)
	{
		if ((temp->index == -1) && (temp->value < min_nodo->value || aux == 0))
		{
			min_nodo = temp;
			aux = 1;
		}
		temp = temp->next_nodo;
	}
	return (min_nodo);
}

void	ft_index(t_Stack **stack)
{
	t_Stack	*temp;
	int		len;
	int		index;
	int		i;

	index = 0;
	temp = *stack;
	i = 0;
	len = ft_lstsize(*stack);
	while (i < len)
	{
		temp = ft_min(stack);
		temp->index = index++;
		i++;
	}
}

void	ft_init(t_Stack **stack, int value)
{
	t_Stack	*nodo;

	nodo = ft_lstnew(value);
	if (nodo == NULL)
		ft_error(stack);
	ft_lstadd_back(stack, nodo);
}

void	ft_error(t_Stack **stack_a)
{
	char	*v_error;
	int		i;

	v_error = "Error\n";
	i = 0;
	while (v_error[i])
	{
		write(2, &v_error[i], 1);
		i++;
	}
	ft_free_stack(stack_a);
	exit (-1);
}
