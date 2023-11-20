/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:31:02 by maricont          #+#    #+#             */
/*   Updated: 2023/10/09 10:12:45 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"

static int	ft_validate_chk_nbr(t_Stack **stack, char *argv, int signo)
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

static int	ft_validate_chk(t_Stack **stack, char *argv[], int argc)
{
	int		i;
	char	**str;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == NULL)
			ft_init(stack, ft_validate_chk_nbr(stack, argv[i], 1));
		else
		{
			str = ft_split(argv[i], ' ');
			while (str[j])
			{
				ft_init(stack, ft_validate_chk_nbr(stack, str[j], 1));
				j++;
			}
		}
		i++;
	}
	return (0);
}

static void	ft_validate_push(t_Stack **stack_a, t_Stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_bonus(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_bonus(stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		ft_rot_bonus(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rot_bonus(stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rot_rev_bonus(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rot_rev_bonus(stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		ft_push_bonus(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "rrr") == 0)
		return ;
	else
		ft_error(stack_a);
}

static void	ft_get_line(t_Stack **stack_a, t_Stack **stack_b, char *line)
{
	if (ft_sort_validate(stack_a) == -1)
	{
		while (line)
		{
			line = get_next_line(0);
			if (line)
				ft_validate_push(stack_a, stack_b, line);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_Stack	**stack_a;
	t_Stack	**stack_b;
	char	*line;

	if (argc < 2)
		return (-1);
	stack_a = (t_Stack **)malloc(sizeof(t_Stack));
	if (!stack_a)
		return (-1);
	ft_validate_chk(stack_a, argv, argc);
	ft_duplicate_chk(stack_a);
	ft_index(stack_a);
	stack_b = (t_Stack **)malloc(sizeof(t_Stack));
	if (!stack_b)
		return (-1);
	line = "";
	*stack_b = NULL;
	ft_get_line(stack_a, stack_b, line);
	if (ft_sort_validate(stack_a) == -1 || *stack_b)
		write(2, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
