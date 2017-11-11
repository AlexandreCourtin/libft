/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:07:30 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/11 17:25:31 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void*)content;
	if (!content)
		list->content_size = 0;
	else
		list->content_size = content_size;
	list->next = NULL;
	free(list);
	return (list);
}