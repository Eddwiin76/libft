# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 09:33:37 by tpierre           #+#    #+#              #
#    Updated: 2021/06/28 16:15:22 by tpierre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

##################################### DIRS #####################################

INC_DIR		=	includes

SRC_DIR		=	srcs

OBJ_DIR		=	objs

IO_DIR		=	ft_io

LST_DIR		=	ft_lst

MEM_DIR		=	ft_mem

PTF_DIR		=	ft_printf

STR_DIR		=	ft_str

##################################### SRCS #####################################

# **************************************************************************** #
# Input/Output :

IO_FILES	=	$(addprefix $(IO_DIR)/, \
				ft_putadr_fd.c ft_putadr.c ft_putchar_fd.c ft_putchar.c \
				ft_putendl_fd.c ft_putendl.c ft_puthexa_fd.c ft_puthexa.c \
				ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
				ft_putuhexa_fd.c ft_putuhexa.c ft_putunbr_fd.c ft_putunbr.c \
				get_next_line.c)

# **************************************************************************** #
# Lists :

LST_FILES	=	$(addprefix $(LST_DIR)/, \
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				ft_lstnew.c ft_lstsize.c)

# **************************************************************************** #
# Memory :

MEM_FILES	=	$(addprefix $(MEM_DIR)/, \
				ft_bzero.c ft_calloc.c ft_free_null.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_realloc.c)

# **************************************************************************** #
# Printf :

PTF_FILES	=	$(addprefix $(PTF_DIR)/, \
				ft_flag_adr.c ft_flag_char.c ft_flag_hexa.c ft_flag_int.c \
				ft_flag_per.c ft_flag_str.c ft_flag_uhexa.c ft_flag_uint.c \
				ft_get_indicator.c ft_get.c ft_initialyze.c ft_parser.c \
				ft_printf.c ft_utils.c)

# **************************************************************************** #
# Strings :

STR_FILES	=	$(addprefix $(STR_DIR)/, \
				ft_atoi_long.c ft_atoi.c ft_isalldigit.c ft_isalnum.c ft_isalpha.c \
				ft_isnumeric.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_sort_int_tab.c ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c \
				ft_strcountchar.c ft_strcpy.c ft_strdelchar.c ft_strdup.c \
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strmapi.c ft_strncmp.c ft_strnlen.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tabdel.c \
				ft_tabmaxlen.c ft_tabsize.c ft_tolower.c ft_toupper.c)

# **************************************************************************** #

SRCS		=	$(IO_FILES) $(LST_FILES) $(MEM_FILES) $(PTF_FILES) $(STR_FILES)

##################################### OBJS #####################################

OBJS		=	$(SRCS:.c=.o)

OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJS))

##################################### INCS #####################################

LIBFT_INC	=	$(addprefix $(INC_DIR)/, libft.h)

PTF_INC		=	$(addprefix $(INC_DIR)/, printf.h)

GNL_INC		=	$(addprefix $(INC_DIR)/, get_next_line.h)

HEADERS		=	$(LFT_INC) $(PTF_INC) $(GNL_INC)

INCS		=	$(addprefix -I,$(INC_DIR)/)

##################################### COMP #####################################

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rc

##################################### RULE #####################################


all:		$(NAME)

$(NAME):	$(OBJ) $(HEADERS)
			@$(AR) $(NAME) $(OBJ)
			@$(CLR)
			@echo $(UP) $(CUT) $(UP)
			@$(RM) .cmp
			@echo $(BG)[$(BLB)LIBFT $(BG)COMPILED$(BG)]$(X)

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
			@/bin/mkdir -p $(OBJ_DIR)
			@/bin/mkdir -p objs/ft_io
			@/bin/mkdir -p objs/ft_lst
			@/bin/mkdir -p objs/ft_mem
			@/bin/mkdir -p objs/ft_printf
			@/bin/mkdir -p objs/ft_str

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
				@$(CMP)
				@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
				@$(CLR)
				@echo -n $@

clean:
			@echo $(R)Cleaning $(X)the $(B)Libft $(X)files...
			@$(RM) $(OBJ) $(OBJ_DIR)
			@echo $(UP) $(CUT) $(UP)
			@echo $(BG)[$(BLB)LIBFT $(BG)CLEANED$(BG)]$(X)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

##################################### UTIL #####################################

CMP			=	if [ ! -e .cmp ]; then \
			echo $(BY)Compiling $(B)Libft $(X)files...$(BY); \
			touch .cmp; fi

RM			=	rm -rf

#################################### DISPLAY ####################################

BY			=	"\033[1;33m"
BR			=	"\033[1;31m"
BG			=	"\033[1;32m"
BLB			=	"\033[1;36m"
BP			=	"\033[1;35m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[0;32m"
B			=	"\033[34m"
P			=	"\033[35m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "
CUT_UP		=	$(UP)$(CUT)$(UP)

#################################### OTHER #####################################

.PHONY:		all clean fclean re
