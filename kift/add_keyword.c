/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_keyword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:45:33 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 16:56:25 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_keyword(t_knowledge *knowledge, char *word)
{
	t_keyword	*keyword;
	t_keyword	*temp;

	keyword = malloc(sizeof(t_keyword));
	if (!keyword)
		exit(1);
	keyword->value = ft_strdup(word);
	keyword->next = NULL;
	temp = knowledge->keywords;
	if (temp == NULL)
	{
		knowledge->keywords = keyword;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = keyword;
}
