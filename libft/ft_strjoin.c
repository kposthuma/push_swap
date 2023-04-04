/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:00:33 by kposthum      #+#    #+#                 */
/*   Updated: 2022/12/28 19:13:17 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*c;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	a = (char *)s1;
	b = (char *)s2;
	c = (char *)ft_calloc((i + 1), sizeof(char));
	if (!c)
		return (0);
	ft_strlcpy(c, a, (ft_strlen(s1) + 1));
	ft_strlcat(c, b, (i + 1));
	return (c);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}*/