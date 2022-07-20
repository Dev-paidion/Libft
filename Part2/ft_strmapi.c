/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:58:56 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/20 14:34:10 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	i = 0;
	p = ft_strdup(s);
	if (p == 0)
		return (0);
	while (s[i])
	{
		p[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (p);
}
