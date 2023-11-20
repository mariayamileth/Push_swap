/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:52:57 by maricont          #+#    #+#             */
/*   Updated: 2023/10/04 13:09:23 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate(t_Stack **stack, char *argv, int signo)
{
	int long	value;
	int			i;

	i = 0;
	value = 0;
	if (!argv[0])
		ft_error(stack);
	if (argv[0] == '-' && argv[1])
	{
		signo = -1;
		i++;
	}
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			value = argv[i] - '0' + (value * 10);
		else
			ft_error(stack);
		i++;
	}
	value = value * signo;
	if (value > 2147483647 || value < -2147483648)
		ft_error(stack);
	return (value);
}

int	ft_validate_argv(t_Stack **stack, char *argv[], int argc)
{
	int		i;
	char	**str;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == NULL)
			ft_init(stack, ft_validate(stack, argv[i], 1));
		else
		{
			str = ft_split(argv[i], ' ');
			while (str[j])
			{
				ft_init(stack, ft_validate(stack, str[j], 1));
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_duplicate(t_Stack **stack)
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

static void	ft_sort_main(t_Stack **stack_a, t_Stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		ft_swap(stack_a, "sa");
	}
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		ft_sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		ft_sort_5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
	{
		ft_sort_all(stack_a, stack_b);
		ft_sort_end(stack_a, stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_Stack	**stack_a;
	t_Stack	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_Stack **)malloc(sizeof(t_Stack));
	if (!stack_a)
		return (-1);
	*stack_a = NULL;
	ft_validate_argv(stack_a, argv, argc);
	ft_duplicate(stack_a);
	ft_index(stack_a);
	stack_b = (t_Stack **)malloc(sizeof(t_Stack));
	if (!stack_b)
		return (-1);
	*stack_b = NULL;
	if (ft_sort_validate(stack_a) == -1)
		ft_sort_main(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
