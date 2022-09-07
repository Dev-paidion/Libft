/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:45:01 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/28 12:44:36 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_tmp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		p_tmp = (*lst)->next;
		free(*lst);
		*lst = p_tmp;
	}
}
