/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_empty.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 13:38:43 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:13:29 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*empty_b(t_list **lista, t_list **listb)
{
	t_list	*sta;
	t_list	*stb;

	sta = *lista;
	stb = *listb;
	while (stb)
		list_push(&stb, &sta, 'a');
	return (sta);
}

t_list	*push_back(t_list **lista, t_list **listb)
{
	t_list	*sta;
	t_list	*stb;

	sta = *lista;
	stb = *listb;
	while (stb)
	{
		stb = list_revrotate(stb, 'b');
		list_push(&stb, &sta, 'a');
	}
	return (sta);
}

t_list	*push_back_(t_list **lista, t_list **listb)
{
	t_list	*sta;
	t_list	*stb;

	sta = *lista;
	stb = *listb;
	while (stb)
	{
		stb = list_revrotate(stb, 'c');
		list_push(&stb, &sta, 'c');
	}
	return (sta);
}

t_list	*twisted_push(t_list **lista, t_list **listb)
{
	t_list	*sta;
	t_list	*stb;

	sta = *lista;
	stb = *listb;
	while (stb)
	{
		stb = list_revrotate(stb, 'b');
		list_push(&stb, &sta, 'a');
		sta = list_rotate(sta, 'a');
	}
	return (sta);
}
