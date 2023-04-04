/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_algo2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 19:02:54 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:14:16 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_pos_high(t_list *list)
{
	int	curr;
	int	loc;
	int	high;

	high = (int)list->cnt;
	curr = 0;
	loc = curr;
	while (list != NULL)
	{
		if ((int)list->cnt > high)
		{
			high = (int)list->cnt;
			loc = curr;
		}
		list = list->nxt;
		curr++;
	}
	return (loc);
}

t_list	*b_rotation(t_list *stacka, t_list *stackb)
{
	int	loc;

	while (stackb)
	{
		loc = find_pos_high(stackb);
		if (loc < (ft_lstsize(stackb) / 2))
		{
			while (loc--)
				stackb = list_rotate(stackb, 'b');
		}
		else
		{
			loc = ft_lstsize(stackb) - loc;
			while (loc--)
				stackb = list_revrotate(stackb, 'b');
		}
		list_push(&stackb, &stacka, 'a');
	}
	return (stacka);
}

t_list	*insertion(t_list *stacka, t_list *stackb)
{
	while (stackb)
	{
		while ((int)stackb->cnt > (int)stacka->cnt)
			stacka = list_rotate(stacka, 'a');
		while ((int)stackb->cnt < (int)ft_lstlast(stacka)->cnt
			&& (int)stacka->cnt > (int)ft_lstlast(stacka)->cnt)
			stacka = list_revrotate(stacka, 'a');
		list_push(&stackb, &stacka, 'a');
	}
	return (stacka);
}

t_list	*rotation(t_list *stacka)
{	
	while (check_ascent(&stacka) != 0)
		stacka = list_revrotate(stacka, 'a');
	return (stacka);
}

t_list	*insertsort(t_list **lista, int count)
{
	int			med;
	static int	i;
	t_list		*stacka;
	t_list		*stackb;

	stacka = *lista;
	stackb = NULL;
	med = find_median(&stacka, count);
	while (count-- && check_ascent(&stacka) != 0)
	{
		if ((int)stacka->cnt < med)
			list_push(&stacka, &stackb, 'b');
		else
			stacka = list_rotate(stacka, 'a');
	}
	if (check_ascent(&stacka) != 0)
	{
		i++;
		stacka = insertsort(&stacka, ft_lstsize(stacka));
	}
	if (i-- > 0)
		stacka = insertion(stacka, stackb);
	else
		stacka = b_rotation(stacka, stackb);
	return (stacka = rotation(stacka));
}
