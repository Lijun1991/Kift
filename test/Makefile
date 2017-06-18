# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 16:13:57 by jnaddef           #+#    #+#              #
#    Updated: 2017/06/12 19:39:49 by jnaddef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = demo
SRCS = hello_ps.c \
	   create_decoder.c \
	   microphone_input.c \
	   process_input_menu.c \
	   process_input_algo.c \
	   load_knowledge_bases.c \
	   add_keyword.c \
	   contains.c \
	   excute_command.c \
	   handle_timer.c \
	   handle_music.c

LIB_DIR = libft
ODIR = obj

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS =  -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" `pkg-config --cflags --libs pocketsphinx sphinxbase`

.PHONY: all, clean, fclean, re, $(LIB_DIR)

all: $(LIB_DIR) $(NAME)

$(OBJS): header.h

$(LIB_DIR):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lft -L./$(LIB_DIR) -I$(LIB_DIR) \
	-DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
	`pkg-config --cflags --libs pocketsphinx sphinxbase` \

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf demo

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
