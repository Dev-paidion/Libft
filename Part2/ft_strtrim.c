/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:23:29 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/13 16:00:27 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	head;
	size_t	tail;
	size_t	i;

	head = 0;
	while (s1[head] && is_char_in_set(s1[head], set))
		head++;
	tail = ft_strlen(s1);
	while (head < tail && is_char_in_set(s1[tail - 1], set))
		tail--;
	str = (char *)malloc(tail - head + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (head < tail)
	{
		str[i++] = s1[head++];
	}
	str[i] = '\0';
	return (str);
}
