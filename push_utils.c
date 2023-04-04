/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 16:55:46 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:32:06 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_descent(t_list **list)
{
	t_list	*stack;
	t_list	*temp;

	stack = *list;
	while (stack->nxt != NULL)
	{
		temp = stack->nxt;
		if ((int)stack->cnt < (int)temp->cnt)
			return (1);
		stack = stack->nxt;
	}
	return (0);
}

int	check_ascent(t_list **list)
{
	t_list	*stack;
	t_list	*temp;

	stack = *list;
	while (stack->nxt != NULL)
	{
		temp = stack->nxt;
		if ((int)stack->cnt > (int)temp->cnt)
			return (1);
		stack = stack->nxt;
	}
	return (0);
}

int	middle_finder(t_list *list, int count)
{
	int	i;
	int	mid;

	i = 0;
	while (i++ < (count / 2))
		list = list->nxt;
	mid = (int)list->cnt;
	return (mid);
}

int	find_median(t_list **list, int count)
{
	t_list	**copy;
	t_list	*stack;
	int		median;

	copy = list_copy(list);
	stack = *copy;
	stack = dirtysort(&stack);
	median = middle_finder(stack, count);
	ft_lstclear(&stack);
	free(copy);
	return (median);
}

t_list	*dirtysort(t_list **lista)
{
	t_list	*sta;
	t_list	*stb;
	int		pivot;

	sta = *lista;
	stb = NULL;
	pivot = (int)ft_lstlast(sta)->cnt;
	while ((int)sta->cnt != pivot)
	{
		if ((int)sta->cnt < pivot)
			list_push(&sta, &stb, 'c');
		else if ((int)sta->cnt > pivot)
			sta = list_rotate(sta, 'c');
	}
	if (sta != NULL && check_ascent(&sta) != 0)
		sta = dirtysort(&sta);
	if (stb != NULL && check_ascent(&stb) != 0)
		stb = dirtysort(&stb);
	return (sta = push_back_(&sta, &stb));
}
