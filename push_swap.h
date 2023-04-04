/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/24 11:56:41 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:22:17 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"libft/libft.h"

void	error(t_list **list);
char	**kill_argvzero(char **vector, int count, t_list **list);
int		new_count(char **vector);
// void	printlist(t_list *list);

int		make_list(t_list **list, int count, char **vector);
void	check_if_int(int count, char **vector, t_list **list);
void	make_intlist(t_list **list, int count, char **vector);
void	duplics(t_list **list);

char	*dec_to_bin(int dec, t_list **list);
t_list	**list_copy(t_list **list);
int		check_ascent(t_list **list);
int		check_descent(t_list **list);

//allowed actions
void	list_push(t_list **listsrc, t_list **lstdest, char a);
t_list	*list_swap(t_list *list, char a);
t_list	*list_rotate(t_list *list, char a);
t_list	*list_revrotate(t_list *list, char a);

t_list	*empty_b(t_list **lista, t_list **listb);
t_list	*push_back(t_list **lista, t_list **listb);
t_list	*push_back_(t_list **lista, t_list **listb);
t_list	*twisted_push(t_list **lista, t_list **listb);

//based on quicksort
t_list	*dirtysort(t_list **lista);
int		find_median(t_list **list, int count);

t_list	*insertsort(t_list **lista, int count);
t_list	*insertion(t_list *stacka, t_list *stackb);

//hard coded for if list only contains three elements
t_list	*ls_three(t_list **lista);
t_list	*ls_r_three(t_list **lista);

//based on simple stack sorting
// t_list	*slowsort(t_list **lista);

//based on radixsort
int		check_if_same(t_list	**list, int i);
t_list	*sortradix(t_list **lista, int count, int i);

t_list	*shortsort(t_list **list, int count);
t_list	*force_sort(t_list **lista, int count);
#endif