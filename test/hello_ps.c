/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:42:22 by jnaddef           #+#    #+#             */
/*   Updated: 2017/06/14 15:42:07 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void display_menu()
{
	printf("MENU : \n"
			"- Algorithm\n"
			"- Sam\n");
}

void destroy_decoders()
{
	ps_free(g_ps_menu);
	cmd_ln_free_r(g_config_menu);
	ps_free(g_ps_algo);
	cmd_ln_free_r(g_config_algo);
	ps_free(g_ps_command);
	cmd_ln_free_r(g_config_command);
}

void process_input(const char *input, ps_decoder_t **ps)
{
	if (*ps == g_ps_menu)
		process_input_menu(input, ps);
	else if (*ps == g_ps_algo)
		process_input_algo(input, ps);
}

int main(void)
{
	ps_decoder_t	*ps;
	ps_decoder_t	*ps1;
	t_info			info;

/*	char *line;
	int fd1 = open("../ak/train/text.transcription", O_RDONLY);
	int fd2 = open("../ak/train/new.transcription", O_WRONLY | O_CREAT);

	while (get_next_line(fd1, &line))
	{
		int i = 0;
		int active = 0;
		while (line[i])
		{
			if (i == 3)
				active = 1;
			if (active)
			{
				line[i] = ft_toupper(line[i]);
				if (line[i] == '<')
					active = 0;
			}
			write(fd2, &(line[i]), 1);
			i++;
		}
		write(fd2, "\n", 1);
	}
*/
	ft_memset(&info, 0, sizeof(t_info));
	load_knowledge_bases();
	ps = create_decoders();
	ps1 = create_decoders_sam();
	display_menu();
	get_microphone_input(ps1, &info);
	get_microphone_input(ps, &info);
	destroy_decoders();

	return (0);
}
