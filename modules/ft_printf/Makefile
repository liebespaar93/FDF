# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 08:16:11 by kyoulee           #+#    #+#              #
#    Updated: 2022/09/02 17:29:39 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
DFLAGS = $(NULL)
IFLAGS =						\
	-I $(INCLUDE_DIR)			\
	-I $(INCLUDE_LIBFT_DIR)
LDFLAGS =						\
	-L $(LIBFT_DIR)
LDLIBS =						\
	-lft
	

#####***** COLOR *****#####
BG_RED     = \033[41m
BG_GREEN   = \033[42m
BG_YELLOW  = \033[43m
BG_BLUE    = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN    = \033[46m
BG_LGREY   = \033[47m
BG_DGREY   = \033[100m
BG_LRED    = \033[101m
BG_LGREEN  = \033[102m
BG_LYELLOW = \033[103m
BG_LBLUE   = \033[104m
BG_LMAGENTA= \033[105m
BG_LCYAN   = \033[106m
BG_WHITE   = \033[107m
BG_MAKE1   = \033[48;5;236m
BG_MAKE2   = \033[48;5;238m
BG_MAKE3   = \033[48;5;240m

FG_BLACK   = \033[30m
FG_RED     = \033[31m
FG_GREEN   = \033[32m
FG_YELLOW  = \033[33m
FG_BLUE    = \033[34m
FG_MAGENTA = \033[35m
FG_CYAN    = \033[36m
FG_LGREY   = \033[37m
FG_DGREY   = \033[90m
FG_LRED    = \033[91m
FG_LGREEN  = \033[92m
FG_LYELLOW = \033[93m
FG_LBLUE   = \033[94m
FG_LMAGENTA= \033[95m
FG_LCYAN   = \033[96m
FG_WHITE   = \033[97m
 
CL_BOLD   = \033[1m
CL_DIM    = \033[2m
CL_UDLINE = \033[4m
CL_BLINK  = \033[5m
CL_INVERT = \033[7m
CL_HIDDEN = \033[8m
 
NO_COLOR = \033[0m



ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
INCLUDE_DIR = $(ROOTDIR)/include
MODULES_DIR = $(ROOTDIR)/modules

SRC_DIR = ./src
SRC_PRINTF_DIR = ./src_printf
SRC_PRINTF_PERCENT_DIR = ./src_printf_percent
SRC_PRINTF_PERCENT_CONVERSION_DIR = ./src_printf_percent_conversion
OBJ_DIR = ./obj
OBJ_DIR_CLEAN = ./obj

## MODULES ##
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = $(ROOTDIR)/modules/Libft
INCLUDE_LIBFT_DIR = $(LIBFT_DIR)/include


SRC = ft_printf.c
SRCS_C =	ft_va_arg_index.c

SRCS_PRINTF_C =	src/ft_printf_percent.c

SRCS_PRINTF_PERCENT_C =	src/ft_printf_asterisk.c \
						src/ft_printf_conversion.c \
						src/ft_printf_flag.c \
						src/ft_printf_length.c \
						src/ft_printf_num_type.c \
						src/ft_printf_precision.c \
						src/ft_printf_width.c

SRCS_PRINTF_PERCENT_CONVERSION_C =	src/ft_printf_a_trans.c \
									src/ft_printf_cs.c \
									src/ft_printf_dioux.c \
									src/ft_printf_fega.c \
									src/ft_printf_n.c \
									src/ft_printf_p.c \
									src/ft_printf_syntax_error.c \
									src/ft_printf_syntaxing.c

SRCS = $(notdir $(SRCS_C))
SRCS_PRINTF = $(notdir $(SRCS_PRINTF_C))
SRCS_PRINTF_PERCENT = $(notdir $(SRCS_PRINTF_PERCENT_C))
SRCS_PRINTF_PERCENT_CONVERSION = $(notdir $(SRCS_PRINTF_PERCENT_CONVERSION_C))

OBJS = $(SRC:.c=.o) $(SRCS:.c=.o) $(SRCS_PRINTF:.c=.o) $(SRCS_PRINTF_PERCENT:.c=.o) $(SRCS_PRINTF_PERCENT_CONVERSION:.c=.o)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))

all: $(NAME)

bonus: $(NAME)

$(OBJ_DIR) :
	mkdir obj

$(MODULES_DIR) :
	mkdir modules

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar -src $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PRINTF_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PRINTF_PERCENT_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PRINTF_PERCENT_CONVERSION_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@
	
OBJS_CLEAN = $(OBJECTS)

## MODULES ##
$(LIBFT): $(MODULES_DIR)
	if [ -d $(ROOTDIR)/../Libft ]; then ln -s $(ROOTDIR)/../Libft $(LIBFT_DIR); fi
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)Libft$(NO_COLOR) -> $(FG_LCYAN)$(LIBFT)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "$(NO_COLOR)"

## MODULES ##
clean_libft :
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(LIBFT))$(NO_COLOR)$(BG_MAKE1)" \
		$(MAKE) -C $(LIBFT_DIR) fclean \
		@echo "$(NO_COLOR)" ;\
	fi


clean : clean_libft
	rm -f $(OBJS_CLEAN)
	find ./ -type l | xargs rm 

fclean : OBJS_CLEAN+=$(NAME)
fclean : clean

re : fclean all

.PHONY: all clean fclean re bonus clean_libft
