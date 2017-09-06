/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:42:17 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 20:58:35 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*check_knowledge(t_knowledge *knowledge, const char *input)
{
	t_keyword	*keyword;

	keyword = knowledge->keywords;
	while (keyword)
	{
		if (!contains(input, keyword->value))
		{
			return (NULL);
		}
		keyword = keyword->next;
	}
	return (knowledge->answer);
}

void	process_input_algo(const char *input, ps_decoder_t **ps)
{
	int			max_priority;
	char		*max_answer;
	t_knowledge	*knowledge;
	char		*answer;

	if (contains(input, "MENU"))
	{
		*ps = g_ps_menu;
		printf("Going back to the MENU\n");
		return ;
	}
	max_answer = NULL;
	max_priority = 0;
	knowledge = algo_kb->knowledges;
	while (knowledge)
	{
		if (knowledge->priority > max_priority)
		{
			answer = check_knowledge(knowledge, input);
			if (answer != NULL)
			{
				max_priority = knowledge->priority;
				max_answer = answer;
			}
		}
		knowledge = knowledge->next;
	}
	if (max_answer != NULL)
		printf("ANSWER : %s\n", max_answer);
	else
		printf("Sorry I do not seem to have the answer to this question\n");
}
