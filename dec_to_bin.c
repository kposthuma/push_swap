/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dec_to_bin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 13:29:14 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/08 18:27:25 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static char	*binpos(int dec)
{
	char	*bin;
	int		i;
	int		temp;

	bin = malloc(33);
	if (!bin)
		return (NULL);
	bin[32] = '\0';
	i = 31;
	while (i != 0)
	{
		temp = dec;
		if (temp % 2 == 0)
			bin[i] = '0';
		else
			bin[i] = '1';
		dec = dec / 2;
		i--;
	}
	bin[0] = '1';
	return (bin);
}

static char	*binneg(int dec)
{
	char	*bin;
	int		i;
	int		temp;

	bin = malloc(33);
	if (!bin)
		return (NULL);
	bin[32] = '\0';
	i = 31;
	dec += 1;
	dec *= -1;
	while (i != 0)
	{
		temp = dec;
		if (temp % 2 == 0)
			bin[i] = '1';
		else
			bin[i] = '0';
		dec = dec / 2;
		i--;
	}
	bin[0] = '0';
	return (bin);
}

char	*dec_to_bin(int dec, t_list **list)
{
	char	*bin;

	if (dec < 0)
		bin = binneg(dec);
	else
		bin = binpos(dec);
	if (bin == NULL)
	{
		ft_lstclear(list);
		exit (-2);
	}
	return (bin);
}
