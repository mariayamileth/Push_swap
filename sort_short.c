/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:13:27 by maricont          #+#    #+#             */
/*   Updated: 2023/10/04 11:26:49 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_3(t_Stack **stack)
{
	t_Stack	*temp;
	int		max;

	temp = *stack;
	max = ft_max_index(stack);
	if ((*stack)->index == max)
		ft_rot(stack, "ra");
	else if ((*stack)->next_nodo->index == max)
		ft_rot_rev(stack, "rra");
	if ((*stack)->index > (*stack)->next_nodo->index)
		ft_swap(stack, "sa");
	return (0);
}

int	ft_sort_4(t_Stack **stack_a, t_Stack **stack_b)
{
	int		k;

	k = 0;
	while (k < 1)
	{
		if ((*stack_a)->index == 0)
		{
			ft_push(stack_a, stack_b, "pb");
			k++;
		}
		else if (k != 1)
			ft_rot(stack_a, "ra");
	}
	ft_sort_3(stack_a);
	ft_push(stack_b, stack_a, "pa");
	return (0);
}

int	ft_sort_5(t_Stack **stack_a, t_Stack **stack_b)
{
	int		k;

	k = 0;
	while (k < 2)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			ft_push(stack_a, stack_b, "pb");
			k++;
		}
		else if (k != 2)
			ft_rot(stack_a, "ra");
	}
	ft_sort_3(stack_a);
	if ((*stack_b)->index < (*stack_b)->next_nodo->index)
		ft_swap(stack_b, "sb");
	ft_push(stack_b, stack_a, "pa");
	ft_push(stack_b, stack_a, "pa");
	return (0);
}

void	ft_print_inst(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, &"\n", 1);
}
