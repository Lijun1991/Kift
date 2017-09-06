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

void	excute_command(char const *hyp, t_info *info)
{
	if (!ft_strcmp(hyp, "SAM"))
		system("say I am Sam, how may I help you");
	handle_music(hyp, info);
	handle_timer(hyp, info);
	// if (!ft_strcmp(hyp, "set an alarm"))
	// 	system("say set an alarm for when today");
}