/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:00:42 by kposthum      #+#    #+#                 */
/*   Updated: 2022/10/13 14:48:04 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;
	char			*a;

	i = 0;
	c = (char *)s;
	a = (char *)ft_calloc((ft_strlen(c) + 1), sizeof(char));
	if (!a)
		return (0);
	while (c[i])
	{
		a[i] = f(i, c[i]);
		i++;
	}
	return (a);
}
