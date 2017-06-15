/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:10:55 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 19:54:24 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		contains(const char *from, const char *needle)
{
	int i;
	int j;

	i = 0;
	while (from[i])
	{
		j = 0;
		while (needle[j] && ft_tolower(from[i + j]) == ft_tolower(needle[j]))
		{
			j++;
		}
		if (j == ft_strlen(needle))
			return (1);
		i++;
	}
	return (0);
}
