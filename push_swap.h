/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:54:30 by maricont          #+#    #+#             */
/*   Updated: 2023/10/09 09:24:55 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_Stack
{
	int						value;
	int						index;
	struct s_Stack			*next_nodo;
}	t_Stack;

void	ft_init(t_Stack **stack, int value);
t_Stack	*ft_lstnew(int n);
void	ft_lstadd_back(t_Stack **stack, t_Stack *nodo);
t_Stack	*ft_lstlast(t_Stack *stack);
int		ft_lstsize(t_Stack *stack);
int		ft_sort_validate(t_Stack **stack);
void	ft_print_stack(t_Stack **stack);
void	ft_free_stack(t_Stack **stack);
void	ft_lstadd_front(t_Stack **stack, t_Stack *nodo);
int		ft_max_index(t_Stack **stack);
void	ft_rot(t_Stack **stack, char *str);
void	ft_swap(t_Stack **stack, char *str);
void	ft_rot_rev(t_Stack **stack, char *str);
int		ft_sort_3(t_Stack **stack);
int		ft_sort_4(t_Stack **stack_a, t_Stack **stack_b);
void	ft_push(t_Stack **stack_a, t_Stack **stack_b, char *str);
int		ft_move(t_Stack **stack_src, t_Stack **stack_dest);
int		ft_sort_5(t_Stack **stack_a, t_Stack **stack_b);
void	ft_sort_all(t_Stack **stack_a, t_Stack **stack_b);
int		ft_sort_rev(t_Stack **stack_a, t_Stack **stack_b);
int		ft_position_index(t_Stack **stack, int index);
void	ft_sort_end(t_Stack **stack_a, t_Stack **stack_b);
char	*ft_strchr(const char *s, int c);
void	ft_index(t_Stack **stack);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	ft_error(t_Stack **stack_a);
void	ft_print_inst(char *str);
int		ft_duplicate(t_Stack **stack);
int		ft_validate(t_Stack **stack, char *argv, int signo);
int		ft_validate_argv(t_Stack **stack, char *argv[], int argc);
void	ft_swap_bonus(t_Stack **stack);
void	ft_rot_bonus(t_Stack **stack);
void	ft_rot_rev_bonus(t_Stack **stack);
int		ft_move_bonus(t_Stack **stack_src, t_Stack **stack_dest);
void	ft_push_bonus(t_Stack **stack_a, t_Stack **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_duplicate_chk(t_Stack **stack);

#endif
