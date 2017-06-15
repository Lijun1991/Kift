/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_decoder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:34:27 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/13 16:17:38 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ps_decoder_t *create_decoders()
{
	// MENU
	g_config_menu = cmd_ln_init(NULL, ps_args(), TRUE,
						"-hmm", MODELDIR "/en-us/en-us",
						//"-lm", "models/menu.lm",
						"-kws", "models/menu.kws",
						"-dict", "models/menu.dic",
						//"-logfn", "/dev/null", 
						NULL);
	if (g_config_menu == NULL)
	{
		fprintf(stderr, "Problem with config creation for MENU\n");
		return NULL;
	}
	g_ps_menu = ps_init(g_config_menu);
	if (g_ps_menu == NULL)
	{
		fprintf(stderr, "Problem with recogniser creation for MENU\n");
		return NULL;
	}
	
	// ALGO
	g_config_algo = cmd_ln_init(NULL, ps_args(), TRUE,
						"-hmm", MODELDIR "/en-us/en-us",
						"-lm", "models/algo.lm",
						"-dict", "models/algo.dic",
						"-logfn", "/dev/null",
					   	"-mllr", "mllr_matrix",	
						NULL);
	if (g_config_algo == NULL)
	{
		fprintf(stderr, "Problem with config creation for ALGO\n");
		return NULL;
	}
	g_ps_algo = ps_init(g_config_algo);
	if (g_ps_algo == NULL)
	{
		fprintf(stderr, "Problem with recogniser creation for ALGO\n");
		return NULL;
	}

	return (g_ps_menu); // Set current recogniser as MENU
}
