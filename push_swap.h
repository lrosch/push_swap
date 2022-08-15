/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:24:09 by lrosch            #+#    #+#             */
/*   Updated: 2022/07/29 13:55:43 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft+/libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/*		algorithms		*/
void			ft_sort_small(t_stack **stack, int i);
void			ft_sort_smallish(t_stack **A, int i);
void			ft_sort_big(t_stack **A, int argc);

/*		math_utils		*/
int				*ft_assign(int argc, char **argv);
int				ft_index(int *arr, int num, int argc);
int				get_position(t_stack *stack, int num);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);

/*		lst_utils		*/
void			lstadd_front(t_stack **lst, t_stack *new);
int				lstadd_back(t_stack **lst, t_stack *new);
t_stack			*lstlast(t_stack *lst);
t_stack			*lstnew(int nbr);

/*    algorithm_utils   */
int				ft_nbr_of_bits(int i);
void			ft_navigate(t_stack **A, int argc, int *arr, char **array);

/*    sort_operations   */
void			rotate(t_stack **stack, char letter);
void			swap(t_stack *stack, char letter);
t_stack			*rev_rotate(t_stack **stack, char letter);
t_stack			*push(t_stack **stack1, t_stack **stack2, char letter);

/*    error_checking    */
void			error_checking(int argc, char **argv);
int				ft_duplicate(char **s, int i);
int				ft_notint(char *s);
int				is_sorted(t_stack *stack);
long long int	ft_atoi_big(const char *str);

/*    free_functions    */
void			ft_free_2d(char **array);
void			ft_freeall(t_stack *lst, int *arr, char **array);

/*		bandaids		*/
int				*ft_assign_split(int argc, char **argv);
int				ft_empty(char *s);
int				*more_assigning(int *A1, int *A2, char **array, int argc);
int				*more_assigning_split(int *A1, int *A2, char **array, int argc);
int				ft_element_nbr(char	**array);

/*	  more-bandaids 	*/
int				ft_duplicate_split(char **s, int i);
void			error_checking_split(int argc, char **arr);

#endif
