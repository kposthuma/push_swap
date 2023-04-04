/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_make.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 14:12:07 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/14 13:23:13 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	**kill_argvzero(char **vector, int count, t_list **list)
{
	char	**newvector;
	int		i;

	newvector = ft_calloc(count, sizeof(char **));
	if (!newvector)
	{
		ft_lstclear(list);
		exit (0);
	}
	i = 0;
	while (i < count)
	{
		newvector[i] = ft_strdup(vector[i + 1]);
		if (!newvector[i])
		{
			ft_free(newvector, count);
			exit(-2);
		}
		i++;
	}
	return (newvector);
}

int	new_count(char **vector)
{
	int	i;

	i = 0;
	while (vector[i])
		i++;
	return (i);
}

void	duplics(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list;
	while (temp1 != NULL)
	{
		temp2 = temp1->nxt;
		while (temp2)
		{
			if ((int)temp2->cnt == (int)temp1->cnt)
				error(list);
			temp2 = temp2->nxt;
		}
		temp1 = temp1->nxt;
	}
}

void	make_intlist(t_list **list, int count, char **vector)
{
	long	j;
	int		i;
	t_list	*node;

	i = count;
	*list = NULL;
	while (count > 0)
	{
		count--;
		j = ft_atol(vector[count]);
		if (j > 2147483647 || j < -2147483648)
		{
			ft_free(vector, i - 1);
			error (list);
		}
		node = ft_lstnew((void *)j);
		if (!node)
		{
			ft_lstclear(list);
			ft_free(vector, i);
			exit(-2);
		}
		ft_lstadd_front(list, node);
	}
	ft_free(vector, (i - 1));
}

void	check_if_int(int count, char **vector, t_list **list)
{
	int	i;

	while (count > 0)
	{
		count--;
		i = 0;
		if ((vector[count][i] != '-' && ft_isdigit((int)vector[count][i]) != 1)
			|| (vector[count][0] == '-' && !vector[count][1]))
			error(list);
		i++;
		while (vector[count][i])
		{
			if (ft_isdigit((int)vector[count][i]) != 1 || i > 10
				|| (vector[count][0] != '-' && i > 9))
				error(list);
			i++;
		}
	}
}
