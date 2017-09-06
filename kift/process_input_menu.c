/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:40:00 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 20:43:19 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void process_input_menu(const char *input, ps_decoder_t **ps)
{
	if (contains(input, "algo"))
	{
		*ps = g_ps_algo;
		printf("Going to the ALGO part\n");
	}
	else if (contains(input, "sam"))
	{
		*ps = g_ps_command;
		printf("Going to the SAM part\n");
	}
}
