/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_knowledge_bases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:15:54 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/11 17:51:07 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_knowledge(t_kb *kb, t_knowledge *knowledge)
{
	t_knowledge *temp;
  
   	printf("Adding to kb\n");
	temp = kb->knowledges; 
	if (temp == NULL)
	{
		kb->knowledges = knowledge;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = knowledge;
   	printf("Added to kb\n");	
}

int count_infos(char *line)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			cpt++;
		i++;
	}
	return (cpt / 2);
}

char **parse_infos(char *line)
{
	char **infos;
	int nb_infos;
	int i;
	int info;
	int cpt;

	nb_infos = count_infos(line);
	printf("%d infos\n", nb_infos);
	infos = malloc(sizeof(char *) * (nb_infos + 1));
	if (!infos)
		exit(1);
	i = 0;
	info = 0;
	cpt = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			if (!info)
			{
				infos[cpt] = &(line[i + 1]);
				cpt++;
			}
			else
				line[i] = '\0';
			info = info ^ 1;
		}
		i++;
	}
	infos[cpt] = NULL;
	return (infos);
}

void	retrieve_line_infos(t_knowledge *knowledge, char *line, int cpt)
{
	char **infos;
	int i;
	t_keyword	*keyword;

	i = 0;
	ft_putstr("about to parse infos\n");
	infos = parse_infos(line);
	ft_putstr("infos parsed\n");
	while (infos[i])
	{
		if (cpt == 0)
		{
			add_keyword(knowledge, infos[i]);
			printf("keyword \"%s\" added\n", infos[i]);
		}
		else if (cpt == 1)
		{
			// Do nothing
		}
		else if (cpt == 2)
		{
			knowledge->answer = ft_strdup(infos[i]);
			printf("answer \"%s\" added\n", knowledge->answer);
		}
		else if (cpt == 3)
		{
			knowledge->priority = ft_atoi(infos[i]);
			printf("priority \"%d\" added\n", knowledge->priority);
		}
		i++;
	}
}

void	load_knowledge_bases(void)
{
	int 		fd;
	char 		*line;
	t_keyword	*keyword;
	t_knowledge	*knowledge;
	int 		cpt;

	fd = open("kb/algo.kb", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File kb/algo.kb could not be opened\n");
		exit(0);	
	}
	algo_kb = malloc(sizeof(t_kb));
	if (!algo_kb)
		exit(1);
	algo_kb->knowledges = NULL;
	cpt = -1;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		if (ft_strlen(line) == 0)
			continue;
		if (strcmp(line, "}") == 0)
		{
			add_knowledge(algo_kb, knowledge);
		}
		else if (strcmp(line, "{") == 0)
		{
			knowledge = malloc(sizeof(t_knowledge));
			if (!knowledge)
				exit(1);
			knowledge->keywords = NULL;
			knowledge->next = NULL;
			cpt = 0;
		}
		else
		{
			retrieve_line_infos(knowledge, line, cpt);
			cpt++;
		}
	}
}
