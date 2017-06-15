/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_sports.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:45:32 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 20:44:16 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void process_input_sports(const char *input, ps_decoder_t **ps)
{
	if (contains(input, "MENU"))
	{
		*ps = g_ps_menu;
		printf("Going back to the MENU\n");
		return ;
	}
	printf("SPORTS not implemented yet\n");
}
