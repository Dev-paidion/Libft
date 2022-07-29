/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:36:11 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/26 20:00:00 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	while (i < len)
	{
		p_dst[len - 1 - i] = p_src[len - 1 - i];
		i++;
	}
	return (dst);
}
