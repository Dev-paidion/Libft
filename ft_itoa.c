/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:13:09 by kjungoo           #+#    #+#             */
/*   Updated: 2022/07/29 12:56:04 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_length(int n)
{
	int	len;

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
	int		len;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_get_length(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	p[len--] = '\0';
	while (len >= 0)
	{
		p[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}
