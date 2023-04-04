/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_algo3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:02:57 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:21:11 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	simplification(t_list *temp, t_list *node, long i)
{
	while ((int)temp->cnt != (int)node->cnt)
		node = node->nxt;
	node->cnt = (void *)i;
}

t_list	*reduce_list(t_list **lista)
{
	t_list	**copy;
	t_list	*temp1;
	t_list	*temp2;
	t_list	*node;
	long	i;

	copy = list_copy(lista);
	temp1 = dirtysort(copy);
	temp2 = temp1;
	node = *lista;
	i = -2147483648;
	while (temp1 != NULL)
	{
		simplification(temp1, node, i);
		temp1 = temp1->nxt;
		i++;
	}
	ft_lstclear(&temp2);
	return (free(copy), node);
}

int	check_if_same(t_list	**list, int i)
{
	t_list	*stack;
	char	*temp1;
	char	*temp2;

	stack = *list;
	temp1 = dec_to_bin((int)stack->cnt, list);
	while (stack->nxt)
	{
		temp2 = dec_to_bin((int)stack->nxt->cnt, list);
		if (temp1[i] != temp2[i])
		{
			free(temp1);
			free(temp2);
			return (1);
		}
		stack = stack->nxt;
		free(temp2);
	}
	return (free(temp1), 0);
}

t_list	*radixdecide(t_list *sta, t_list *stb, int count, int i)
{
	if (check_ascent(&sta) == 0 && check_descent(&stb) == 0
		&& (int)sta->cnt < 0 && (int)stb->cnt > -1)
		sta = twisted_push(&sta, &stb);
	else
		sta = empty_b(&sta, &stb);
	while (check_if_same(&sta, i) == 0)
		i--;
	if (check_ascent(&sta) != 0)
		sta = sortradix(&sta, count, (i - 1));
	return (sta);
}

t_list	*sortradix(t_list **lista, int count, int i)
{
	t_list	*sta;
	t_list	*stb;
	char	*bin;
	int		j;

	sta = reduce_list(lista);
	stb = NULL;
	j = 0;
	while (j++ < count)
	{
		bin = dec_to_bin((int)sta->cnt, lista);
		if (bin[i] == '0')
			list_push(&sta, &stb, 'b');
		else
			sta = list_rotate(sta, 'a');
		free(bin);
		if (check_ascent(&sta) == 0 && check_descent(&stb) == 0)
			return (sta = empty_b(&sta, &stb));
	}
	sta = radixdecide(sta, stb, count, i);
	return (sta);
}
