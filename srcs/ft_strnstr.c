/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:46:26 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/10 18:03:42 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	unsigned long	i;
	int				j;
	int				taille;

	taille = 0;
	while (to_find[taille] != '\0')
	{
		taille += 1;
	}
	if (taille == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0' && i < len)
	{
		while (to_find[j] == str[i + j] && (i + j) < len)
		{
			if (j == taille - 1)
				return (str + i);
			j += 1;
		}
		j = 0;
		i += 1;
	}
	return (NULL);
}
