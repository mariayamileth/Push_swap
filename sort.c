/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:09:53 by maricont          #+#    #+#             */
/*   Updated: 2023/10/04 11:25:54 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_end(t_Stack **stack_a, t_Stack **stack_b)
{
	int		len;

	while (*stack_b)
	{
		len = ft_lstsize(*stack_b);
		if ((ft_position_index(stack_b, len - 1) < len / 2))
		{
			if ((*stack_b)->index == len - 1)
			{
				ft_push(stack_b, stack_a, "pa");
			}
			else
				ft_rot(stack_b, "rb");
		}
		else
		{
			if ((*stack_b)->index == len - 1)
			{
				ft_push(stack_b, stack_a, "pa");
			}
			else
				ft_rot_rev(stack_b, "rrb");
		}
	}
}

void	ft_sort_all(t_Stack **stack_a, t_Stack **stack_b)
{
	int		mid;
	int		nro;
	int		sum;

	nro = 0;
	mid = ft_lstsize(*stack_a) * 0.1;
	if (ft_lstsize(*stack_a) < 400)
		mid = ft_lstsize(*stack_a) * 0.2;
	sum = mid;
	while (*stack_a)
	{
		while (*stack_a && nro < mid)
		{
			if ((*stack_a)->index < mid && nro < mid)
			{
				ft_push(stack_a, stack_b, "pb");
				nro++;
				if (((*stack_b)->index / 10) % 2 == 0)
					ft_rot(stack_b, "rb");
			}
			else
				ft_rot(stack_a, "ra");
		}
		mid = mid + sum;
	}
}
