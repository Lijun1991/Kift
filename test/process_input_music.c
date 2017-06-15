/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_music.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:44:40 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 20:44:06 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void process_input_music(const char *input, ps_decoder_t **ps)
{
	if (contains(input, "MENU"))
	{
		*ps = g_ps_menu;
		printf("Going back to the MENU\n");
		return ;
	}
	printf("MUSIC not implemented yet\n");
}
