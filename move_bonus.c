/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:06:22 by maricont          #+#    #+#             */
/*   Updated: 2023/10/06 13:07:22 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_bonus(t_Stack **stack)
{
	t_Stack	*temp;
	t_Stack	*nxt;
	int		len;
	int		index_temp;
	int		value_temp;

	temp = *stack;
	nxt = temp->next_nodo;
	len = ft_lstsize(*stack);
	if (len > 1)
	{
		if (temp && len > 1)
		{
			index_temp = temp->index;
			value_temp = temp->value;
			temp->index = nxt->index;
			temp->value = nxt->value;
			nxt->index = index_temp;
			nxt->value = value_temp;
		}
	}
}

void	ft_rot_bonus(t_Stack **stack)
{
	t_Stack	*temp;
	int		len;

	len = ft_lstsize(*stack);
	if (len > 2)
	{
		temp = *stack;
		*stack = temp->next_nodo;
		ft_lstadd_back(stack, temp);
	}
	if (len == 2)
		ft_swap_bonus(stack);
}

void	ft_rot_rev_bonus(t_Stack **stack)
{
	t_Stack	*temp;
	t_Stack	*last;
	int		len;

	temp = *stack;
	len = ft_lstsize(*stack);
	if (len > 2)
	{
		last = ft_lstlast(temp);
		while (temp)
		{
			if (temp->next_nodo->next_nodo == NULL)
				temp->next_nodo = NULL;
			temp = temp->next_nodo;
		}
		ft_lstadd_front(stack, last);
	}
	if (len == 2)
		ft_swap_bonus(stack);
}

int	ft_move_bonus(t_Stack **stack_src, t_Stack **stack_dest)
{
	t_Stack	*temp;
	t_Stack	*src;
	int		aux;

	aux = 0;
	if (*stack_src != NULL)
	{
		src = *stack_src;
		temp = *stack_src;
		if (src->next_nodo != NULL)
		{
			*stack_src = src->next_nodo;
			src->next_nodo = (*stack_dest);
			*stack_dest = src;
		}
		else
		{
			src->next_nodo = (*stack_dest);
			*stack_dest = src;
			aux = 1;
		}
		return (aux);
	}
	else
		return (0);
}

void	ft_push_bonus(t_Stack **stack_a, t_Stack **stack_b)
{
	int		i;
	int		aux;

	i = 0;
	aux = 0;
	while (i < 1)
	{
		aux = ft_move_bonus(stack_a, stack_b);
		if (aux == 1)
			*stack_a = NULL;
		i++;
	}
}
