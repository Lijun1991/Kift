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

void	stop_music(void)
{
	system("pkill mpg123");
}

void	play_music(int music)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (music == 0)
		{
			stop_music();
			system("mpg123 Lobby\\ Time.mp3");
		}
		else if (music == 1)
		{
			stop_music();
			system("mpg123 Secret\\ of\\ Tiki\\ Island.mp3");
		}
		else if (music == 2)
		{
			stop_music();
			system("mpg123 Funky\\ Chunk.mp3");
		}
		else
			system("say there is no more music");
		exit(0);
	}
	else if (pid > 0)
		return ;
}

void	cancel_timer(t_info * info)
{
	if (info->timer)
		system("pkill mpg123");
	else
		system("say there is no timer has been seted");
}

char	*get_time(const char *hyp)
{
	// char *s;
	char **tmp;
	int i;

	i = 0;
	// s = (char*)malloc(sizeof(char) * 101);
	tmp = ft_strsplit(hyp, ' ');
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		if (!ft_strcmp(tmp[i], "SECOND") || !ft_strcmp(tmp[i], "MINUTES"))
			return (tmp[i - 1]);
		i++;
	}
	printf("didn't find time\n");
	return (NULL);
}

void	set_a_timer(const char *hyp, int sign, t_info * info)
{
	int		pid;
	char	*s_time;

	if (info->timer)
	{
		s_time = get_time(hyp);
		pid = fork();
		if (pid == 0)
		{
			printf("timer is seted at %s\n", s_time);
			system("say a timer of 10 second has been seted");
			system("sleep 10s && mpg123 \"Jingle Bells 3.mp3\"");
		}
		else if (pid > 0)
		{
			return ;
		}
	}
	else
		system("say do you want to set a timer");
}

void	excute_command(char const *hyp, t_info *info)
{
	if (!ft_strcmp(hyp, "SAM"))
		system("say I am Sam, how may I help you");
	if (!ft_strcmp(hyp, "MUSIC"))
	{
		play_music(info->music);
		info->music++;
	}
	if (!ft_strcmp(hyp, "NEXT MUSIC"))
	{
		play_music(info->music);
		info->music++;
	}
	if (!ft_strcmp(hyp, "STOP MUSIC"))
		stop_music();
	if (!ft_strcmp(hyp, "SET A TIMER"))
	{
		system("say for how long");
		// set_a_timer();
		info->timer++;
	}
	if (contains(hyp, "minutes"))
		set_a_timer(hyp, 1, info);
	if (contains(hyp, "second"))
		set_a_timer(hyp, 2, info);
	if (!ft_strcmp(hyp, "CANCEL TIMER"))
		cancel_timer(info);
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