/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_decoders_sam.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:43:53 by lwang             #+#    #+#             */
/*   Updated: 2017/06/14 22:43:55 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ps_decoder_t *create_decoders_sam()
{
	g_config_command = cmd_ln_init(NULL, ps_args(), TRUE,
						"-hmm", MODELDIR "/en-us/en-us",
						"-lm", "models/3976.lm",
						"-dict", "models/3976.dic",
						//"-logfn", "/dev/null", 
						NULL);
	if (g_config_command == NULL)
	{
		fprintf(stderr, "Problem with config creation for COMMAND\n");
		return NULL;
	}
	g_ps_command = ps_init(g_config_command);
	if (g_ps_command == NULL)
	{
		fprintf(stderr, "Problem with recogniser creation for COMMAND\n");
		return NULL;
	}
	return (g_ps_command);
}
