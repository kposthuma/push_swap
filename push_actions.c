/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/07 11:53:02 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/07 16:24:28 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Take the top element of source list and 
// place it at the top of destination list
void	list_push(t_list **listsrc, t_list **lstdest, char a)
{
	t_list	*temp;

	temp = *listsrc;
	*listsrc = temp->nxt;
	ft_lstadd_front(lstdest, temp);
	if (a == 'a' || a == 'b')
		ft_printf("p%c\n", a);
}

// Swaps the top two elements of a list and
//  returns the first element of the list
t_list	*list_swap(t_list *list, char a)
{
	t_list	*stack;
	t_list	*temp;

	stack = list->nxt;
	temp = stack->nxt;
	list->nxt = temp;
	ft_lstadd_front(&list, stack);
	if (a == 'a' || a == 'b')
		ft_printf("s%c\n", a);
	return (stack);
}

// Rotates the list, placing the first element on the bottom 
// and returning the new first element of the list
t_list	*list_rotate(t_list *list, char a)
{
	t_list	*temp;

	temp = list->nxt;
	ft_lstadd_back(&list, list);
	list->nxt = NULL;
	if (a == 'a' || a == 'b')
		ft_printf("r%c\n", a);
	return (temp);
}

// Rotates the list in reverse, placing the last element on top
//  and returning the new first element of the list
t_list	*list_revrotate(t_list *list, char a)
{
	t_list	*temp;

	temp = ft_lstlast(list);
	ft_lstadd_front(&list, temp);
	temp = ft_lstlast(list);
	temp->nxt = NULL;
	if (a == 'a' || a == 'b')
		ft_printf("rr%c\n", a);
	return (list);
}
