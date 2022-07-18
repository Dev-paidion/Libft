/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:22:53 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/15 16:39:28 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	size_t			i;
	unsigned char	*new_b;

	i = 0;
	new_b = (unsigned char *)b;
	while (i < len)
	{
		new_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
