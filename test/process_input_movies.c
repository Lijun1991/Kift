/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_movies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:43:04 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 20:43:55 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void process_input_movies(const char *input, ps_decoder_t **ps)
{
	if (contains(input, "MENU"))
	{
		*ps = g_ps_menu;
		printf("Going back to the MENU\n");
		return ;
	}
	printf("MOVIES not implemented yet\n");
}
