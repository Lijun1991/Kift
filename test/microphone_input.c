/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microphone_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:28:10 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/12 19:30:22 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void sleep_msec(int32 ms)
{
    struct timeval tmo;

    tmo.tv_sec = 0;
    tmo.tv_usec = ms * 1000;

    select(0, NULL, NULL, NULL, &tmo);
}

void get_microphone_input(ps_decoder_t *ps)
{
	ad_rec_t *ad;
	int32 score;
	int32 k;
	int16 buf[2048];
	uint8 utt_started;
	uint8 in_speech;
	char const *hyp;
	
	if ((ad = ad_open_dev(cmd_ln_str_r(ps_get_config(ps), "-adcdev"),
					(int) cmd_ln_float32_r(ps_get_config(ps), "-samprate"))) == NULL)
		E_FATAL("Failed tp open audio device\n");
	
	if (ad_start_rec(ad) < 0)
		E_FATAL("Failed to start recording\n");
	
	if (ps_start_utt(ps) < 0)
		E_FATAL("Failed to start utterance\n");
	utt_started = FALSE;

	printf("Ready...\n");

	for (;;)
	{
		if ((k = ad_read(ad, buf, 2048)) < 0)
			E_FATAL("Failed to read audio\n");
		ps_process_raw(ps, buf, k, FALSE, FALSE);
		in_speech = ps_get_in_speech(ps);
		if (in_speech && !utt_started)
		{
			utt_started = TRUE;
			printf("Listening...\n");
		}
		if (!in_speech && utt_started)
		{
			ps_end_utt(ps);
			hyp = ps_get_hyp(ps, &score);
			if (hyp != NULL)
			{
				// Process what was said.
				printf("Recognised: %s with score %d\n", hyp, score);
				// excute_command(hyp);
				process_input(hyp, &ps);
				fflush(stdout);
			}
			
			if (ps_start_utt(ps) < 0)
				E_FATAL("Failed to start utterance\n");
			utt_started = FALSE;
			printf("Ready...\n");
		}
		sleep_msec(100);
	}
	ad_close(ad);
}

