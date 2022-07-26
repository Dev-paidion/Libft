/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:58:56 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/21 17:33:04 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	while (s[i])
	{
		p[i] = f((unsigned int)i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
