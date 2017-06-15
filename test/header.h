#ifndef HEADER_H
# define HEADER_H

#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
#include <pocketsphinx.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct	s_keyword
{
	char 				*value;
	struct s_keyword	*next;
}				t_keyword;

typedef struct	s_knowledge
{
	t_keyword			*keywords;
	char 				*answer;
	int 				priority;
	struct s_knowledge	*next;
}				t_knowledge;

typedef struct 	s_kb
{
	t_knowledge	*knowledges;
}				t_kb;

typedef struct	s_info
{
	int music;
	int timer;
	int alarm;
}				t_info;

ps_decoder_t 	*create_decoders();
void			get_microphone_input(ps_decoder_t *ps, t_info *info);
void			process_input(const char *input, ps_decoder_t **ps);
void			process_input_menu(const char *input, ps_decoder_t **ps);
void			process_input_algo(const char *input, ps_decoder_t **ps);
void			process_input_movies(const char *input, ps_decoder_t **ps);
void			process_input_music(const char *input, ps_decoder_t **ps);
void			process_input_sports(const char *input, ps_decoder_t **ps);
void			load_knowledge_bases(void);
void			add_keyword(t_knowledge *kn, char *word);
int				contains(const char *from, const char *needle);

void	excute_command(char const *hyp, t_info *info);
ps_decoder_t	*create_decoders_sam();
void			set_an_alarm(void);
void			stop_music(void);
void			play_music(int music);


ps_decoder_t	*g_ps_menu;
ps_decoder_t 	*g_ps_algo;
ps_decoder_t 	*g_ps_command;
cmd_ln_t 		*g_config_menu;
cmd_ln_t 		*g_config_algo;
cmd_ln_t 		*g_config_command;
t_kb			*algo_kb;

#endif
