/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 16:23:55 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/15 11:34:01 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// makes a copy of a list
t_list	**list_copy(t_list **list)
{
	t_list	**copy;
	t_list	*orig;
	t_list	*dup;

	copy = malloc(sizeof(t_list **));
	if (!copy)
	{
		ft_lstclear(list);
		exit (0);
	}
	*copy = NULL;
	orig = *list;
	while (orig)
	{
		dup = ft_lstnew(orig->cnt);
		if (!dup)
		{
			ft_lstclear(list);
			ft_lstclear(copy);
			exit (0);
		}
		ft_lstadd_back(copy, dup);
		orig = orig->nxt;
	}
	return (copy);
}

// makes a linked list based on arguments given and 
// returns the amount of elements in the list.
int	make_list(t_list **list, int count, char **vector)
{
	if (count == 1)
	{
		if (!vector[1])
			error(list);
		vector = ft_split(vector[1], ' ');
		count = new_count(vector);
		if (count == 0)
		{
			free(vector);
			error(list);
		}
	}
	else
		vector = kill_argvzero(vector, count, list);
	check_if_int(count, vector, list);
	make_intlist(list, count, vector);
	duplics(list);
	if (check_ascent(list) == 0)
	{		
		ft_lstclear(list);
		exit(0);
	}
	return (count);
}

void	error(t_list **list)
{
	if (*list)
		ft_lstclear(list);
	free(list);
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_list	**lista;

	if (argc < 2)
		exit(-1);
	lista = ft_calloc(sizeof(t_list), 1);
	if (lista == NULL)
		return (0);
	argc = make_list(lista, (argc - 1), argv);
	if (argc < 4)
		*lista = shortsort(lista, argc);
	else if (argc < 7)
		*lista = force_sort(lista, argc);
	else if (argc < 150)
		*lista = insertsort(lista, argc);
	else
		*lista = sortradix(lista, argc, 31);
	ft_lstclear(lista);
	exit(0);
}

// void	printlist(t_list	*list)
// {
// 	while (list != NULL)
// 	{
// 		ft_printf("%i, ", (int)list->cnt);
// 		list = list->nxt;
// 	}
// 	ft_printf("\n");
// }
