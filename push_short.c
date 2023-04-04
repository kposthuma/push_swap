/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:25:43 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:21:52 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*three_two_one(t_list *sta)
{
	sta = list_swap(sta, 'a');
	sta = list_revrotate(sta, 'a');
	return (sta);
}

t_list	*one_three_two(t_list *sta)
{
	sta = list_swap(sta, 'a');
	sta = list_rotate(sta, 'a');
	return (sta);
}

t_list	*three_one_two(t_list *sta)
{
	sta = list_rotate(sta, 'a');
	return (sta);
}

t_list	*two_three_one(t_list *sta)
{
	sta = list_revrotate(sta, 'a');
	return (sta);
}

t_list	*ls_three(t_list **lista)
{
	t_list	*sta;
	t_list	*temp;

	sta = *lista;
	temp = sta->nxt;
	if ((int)sta->cnt > (int)temp->cnt && (int)temp->cnt > (int)temp->nxt->cnt)
		sta = three_two_one(sta);
	else if ((int)temp->nxt->cnt > (int)sta->cnt
		&& (int)temp->cnt > (int)temp->nxt->cnt)
		sta = one_three_two(sta);
	else if ((int)temp->nxt->cnt > (int)temp->cnt
		&& (int)sta->cnt > (int)temp->nxt->cnt)
		sta = three_one_two(sta);
	else if ((int)temp->cnt > (int)sta->cnt
		&& (int)sta->cnt > (int)temp->nxt->cnt)
		sta = two_three_one(sta);
	else if ((int)sta->cnt > (int)temp->cnt
		&& (int)sta->cnt < (int)temp->nxt->cnt)
		sta = list_swap(sta, 'a');
	return (sta);
}
