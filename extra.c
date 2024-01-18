/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:24:54 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/31 21:33:06 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	sign = 0;
	num = 0;
	i = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	{
		if (*nptr == '-')
			sign = 1;
		if (*nptr == '-' || *nptr == '+')
			nptr++;
		while (nptr[i] >= 48 && nptr[i] <= 57)
		{
			num = (nptr[i] - 48) + (10 * num);
			i++;
		}
		if (sign == 1)
			num = num * -1;
	}
	return (num);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (str[0] == '-')
		return (res + -res2);
	else
		return (res + res2);
}
