/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:40:19 by kjungoo           #+#    #+#             */
/*   Updated: 2022/09/02 19:07:25 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(long res, const char *str)
{
	if (res == 92233720368547780 && ft_isdigit(*(str + 1)) && *(str + 1) > '7')
	{
		return (1);
	}
	else if (res > 92233720368547780 && ft_isdigit(*(str + 1)))
	{
		return (1);
	}
	return (0);
}

static int	is_underflow(long res, const char *str)
{
	if (res == -922337203685477580 && ft_isdigit(*(str + 1)) \
			&& *(str + 1) > '8')
	{
		return (1);
	}
	else if (res < -92233720368547780 && ft_isdigit(*(str + 1)))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0') * sign;
		if (is_overflow(res, str + i) == 1)
			return ((int)(9223372036854775807));
		else if (is_underflow(res, str + i) == 1)
			return ((int)(-9223372036854775807 - 1));
		i++;
	}
	return ((int)(res));
}
