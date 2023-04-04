/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 09:52:12 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/05 16:02:15 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_free(char **a, int i)
{
	while (i >= 0)
	{
		if (a[i])
			free(a[i]);
		i--;
	}
	if (a)
		free(a);
}
