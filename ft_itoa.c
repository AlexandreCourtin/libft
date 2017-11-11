/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:54:53 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/11 13:01:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fillstr(int neg, long size, int n, char *str)
{
	int i;

	i = 0;
	if (neg == -1)
	{
		str[i] = '-';
		i++;
	}
	while (size > 0)
	{
		str[i] = (n / size) + '0';
		i++;
		n = n % size;
		size /= 10;
	}
	str[i] = '\0';
}

void			calculsize(long *size, int *length, int n)
{
	while (*size <= n)
	{
		*size *= 10;
		*length += 1;
	}
	*size /= 10;
}

char			*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	size;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = 1;
	size = 1;
	neg = 1;
	if (n < 0)
	{
		n = -n;
		neg = -1;
		length++;
	}
	calculsize(&size, &length, n);
	if (n == 0)
		size = 1;
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	fillstr(neg, size, n, str);
	return (str);
}