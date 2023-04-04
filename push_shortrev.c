/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_shortrev.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:25:43 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:21:57 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*r_three_two_one(t_list *sta)
{
	sta = list_swap(sta, 'b');
	sta = list_revrotate(sta, 'b');
	return (sta);
}

t_list	*r_one_three_two(t_list *sta)
{
	sta = list_swap(sta, 'b');
	sta = list_rotate(sta, 'b');
	return (sta);
}

t_list	*r_three_one_two(t_list *sta)
{
	sta = list_rotate(sta, 'b');
	return (sta);
}

t_list	*r_two_three_one(t_list *sta)
{
	sta = list_revrotate(sta, 'b');
	return (sta);
}

t_list	*ls_r_three(t_list **lista)
{
	t_list	*sta;
	t_list	*temp;

	sta = *lista;
	temp = sta->nxt;
	if ((int)sta->cnt < (int)temp->cnt && (int)temp->cnt < (int)temp->nxt->cnt)
		sta = r_three_two_one(sta);
	else if ((int)temp->nxt->cnt < (int)sta->cnt
		&& (int)temp->cnt < (int)temp->nxt->cnt)
		sta = r_one_three_two(sta);
	else if ((int)temp->nxt->cnt < (int)temp->cnt
		&& (int)sta->cnt < (int)temp->nxt->cnt)
		sta = r_three_one_two(sta);
	else if ((int)temp->cnt < (int)sta->cnt
		&& (int)sta->cnt < (int)temp->nxt->cnt)
		sta = r_two_three_one(sta);
	else if ((int)sta->cnt < (int)temp->cnt
		&& (int)sta->cnt > (int)temp->nxt->cnt)
		sta = list_swap(sta, 'b');
	return (sta);
}
