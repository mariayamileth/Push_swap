/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:37:27 by maricont          #+#    #+#             */
/*   Updated: 2023/09/29 09:53:55 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*ft_lstnew(int n)
{
	t_Stack	*nodo;

	nodo = (t_Stack *)malloc(sizeof(*nodo));
	if (!nodo)
		return (NULL);
	nodo->value = n;
	nodo->index = -1;
	nodo->next_nodo = NULL;
	return (nodo);
}

t_Stack	*ft_lstlast(t_Stack *stack)
{
	t_Stack	*temp;

	temp = stack;
	while (temp->next_nodo != NULL)
	{
		temp = temp->next_nodo;
		if (temp->next_nodo == NULL)
			return (temp);
	}
	return (temp);
}

void	ft_lstadd_back(t_Stack **stack, t_Stack *nodo)
{
	t_Stack	*temp;

	if (*stack)
	{
		temp = ft_lstlast(*stack);
		temp->next_nodo = nodo;
		nodo->next_nodo = NULL;
	}
	else
	{
		*stack = nodo;
		(*stack)->next_nodo = NULL;
	}
}

int	ft_lstsize(t_Stack *stack)
{
	t_Stack	*temp;
	int		cont;

	cont = 0;
	temp = stack;
	while (temp)
	{
		cont++;
		temp = temp->next_nodo;
	}
	return (cont);
}

void	ft_lstadd_front(t_Stack **stack, t_Stack *nodo)
{
	nodo->next_nodo = *stack;
	*stack = nodo;
}
