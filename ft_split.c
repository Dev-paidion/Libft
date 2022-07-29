/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:19:53 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/29 17:51:10 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == 0)
		return (0);
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	**ft_free_all(char **p_arr)
{
	size_t	i;

	i = 0;
	while (p_arr[i])
	{
		free(p_arr[i]);
		i++;
	}
	free(p_arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;
	char	**p_arr;

	i = 0;
	count = ft_word_count(s, c);
	p_arr = (char **)malloc(sizeof(char *) + (count + 1));
	if (p_arr == 0)
		return (0);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		len = ft_word_len(s, c);
		p_arr[i] = ft_strndup(s, len);
		if (p_arr[i] == 0)
			return (ft_free_all(p_arr));
		s += len;
		i++;
	}
	p_arr[i] = 0;
	return (p_arr);
}
