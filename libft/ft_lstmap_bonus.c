/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:06:52 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/05 15:55:28 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*nwlst;
	t_list	*filler;
	t_list	*temp;
	void	*ding;

	temp = lst;
	nwlst = 0;
	filler = 0;
	while (temp != 0)
	{
		ding = f(temp->cnt);
		filler = ft_lstnew(ding);
		if (!filler)
		{
			del(ding);
			ft_lstclear(&nwlst);
			return (0);
		}
		ft_lstadd_back(&nwlst, filler);
		temp = temp->nxt;
	}
	return (nwlst);
}
