/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_algo4.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 17:00:21 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:13:30 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*shortsort(t_list **list, int count)
{
	if (check_ascent(list) == 0)
		return (*list);
	if (count == 2)
		*list = list_swap(*list, 'a');
	if (count == 3)
		*list = ls_three(list);
	return (*list);
}

t_list	*r_shortsort(t_list **list, int count)
{
	if (check_descent(list) == 0)
		return (*list);
	if (count == 2)
		*list = list_swap(*list, 'b');
	if (count == 3)
		*list = ls_r_three(list);
	return (*list);
}

t_list	*savelines_savelives(t_list **lista, t_list **listb)
{
	*lista = shortsort(lista, ft_lstsize(*lista));
	*lista = empty_b(lista, listb);
	return (*lista);
}

t_list	*force_sort(t_list **lista, int count)
{
	t_list	*stacka;
	t_list	*stackb;
	int		med;
	int		i;

	med = find_median(lista, count);
	i = 0;
	stacka = *lista;
	stackb = NULL;
	while (i < count)
	{
		if ((int)stacka->cnt < med)
			list_push(&stacka, &stackb, 'b');
		else
			stacka = list_rotate(stacka, 'a');
		i++;
	}
	stackb = r_shortsort(&stackb, ft_lstsize(stackb));
	stacka = savelines_savelives(&stacka, &stackb);
	return (stacka);
}
