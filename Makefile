# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 05:13:25 by asimon            #+#    #+#              #
#    Updated: 2020/11/16 22:51:42 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

COMP		=	gcc -Wall -Werror -Wextra $(PRINTF_H) -c -o

OBJ_DIR		=	./obj/

SRC_DIR		=	./resources/

PRINTF_H	=	-I includes/

CFILE		=	convert_c.c				\
				convert_d.c				\
				convert_i.c				\
				convert_p.c				\
				convert_pourc.c			\
				convert_s.c				\
				convert_u.c				\
				convert_x.c				\
				convert_xx.c			\
				flag_mark.c				\
				flags_application.c		\
				flags_pos.c		\
				parse_flag.c			\
				parse_str.c				\
				ft_init.c				\
				ft_itoa.c				\
				ft_utils.c				\
				ft_utils_2.c			\
				ft_utils_print.c		\
				ft_utils_string.c		\
				read_utils.c						\

OBJS		=	$(SRCS:.c=.o)

CFIND		=	$(CFILE:%=$(SRC_DIR)%)

OFILE		=	$(CFILE:.c=.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OFILE))

CFLAGS		=	-c -Wall -Wextra -Werror

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)

$(OBJ): $(CFIND)
		$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		/bin/rm -rf $(OBJ_DIR)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
