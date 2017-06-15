/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:02:09 by lwang             #+#    #+#             */
/*   Updated: 2017/06/13 14:02:11 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void	play_music(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		system("mpg123 my.mp3");
		exit(0);
	}
	else if (pid > 0)
	{
		return ;
	}
}

void	stop_music(void)
{
	system("pkill mpg123");
}

void	set_a_timer(void)
{
	system("say for how long");
}


void	excute_command(char const *hyp)
{
	if (!ft_strcmp(hyp, "SAM"))
		system("say I am Sam, how may I help you");
	else if (!ft_strcmp(hyp, "MUSIC"))
		play_music();
	if (!ft_strcmp(hyp, "STOP MUSIC"))
		stop_music();
	if (!ft_strcmp(hyp, "SET A TIMER"))
		set_a_timer();
	// if (!ft_strcmp(hyp, "set an alarm"))
	// 	set_an_alarm(alarm);
	// if (!ft_strcmp(hyp, "music"))
	// 	play_mucic();
	// if (!ft_strcmp(hyp, "music"))
	// 	play_mucic();
	// if (!ft_strcmp(hyp, "music"))
	// 	play_mucic();
	// if (!ft_strcmp(hyp, "music"))
	// 	play_mucic();
	// if (!ft_strcmp(hyp, "music"))
	// 	play_mucic();
}