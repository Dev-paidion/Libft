/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:13:09 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/20 14:11:19 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_length(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		sign;
	size_t	len;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_get_length(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	p[len] = '\0';
	while (len-- >= 0)
	{
		p[len] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}
