# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 08:16:11 by kyoulee           #+#    #+#              #
#    Updated: 2022/09/07 01:10:48 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a

CC = cc
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(INCLUDE_DIR)
LDFLAGS = $(NULL)
LDLIBS = $(NULL)

# COLORS
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

#####***** DIR *****#####

ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
SRC_DIR = $(ROOTDIR)/src
SRC_IS_DIR = $(ROOTDIR)/src_is
SRC_LST_DIR = $(ROOTDIR)/src_lst
SRC_MALLOC_DIR = $(ROOTDIR)/src_malloc
SRC_MATH_DIR = $(ROOTDIR)/src_math
SRC_MEMORY_DIR = $(ROOTDIR)/src_memory
SRC_PUT_DIR = $(ROOTDIR)/src_put
SRC_STR_DIR = $(ROOTDIR)/src_str
SRC_TO_DIR = $(ROOTDIR)/src_to

OBJ_DIR = $(ROOTDIR)/obj
INCLUDE_DIR = $(ROOTDIR)/include

## DIMENSION ##
DIMENSIONDIR = $(ROOTDIR)/src_dimension
SRC_AXIS_DIR = $(DIMENSIONDIR)/src_axis
SRC_DIMENSIONAL_ZERO_DIR = $(DIMENSIONDIR)/src_dimensional_zero
SRC_DIMENSIONAL_ONE_DIR = $(DIMENSIONDIR)/src_dimensional_one
SRC_DIMENSIONAL_TWO_DIR = $(DIMENSIONDIR)/src_dimensional_two
SRC_DIMENSIONAL_THREE_DIR = $(DIMENSIONDIR)/src_dimensional_three
SRC_DIMENSIONAL_FOUR_DIR = $(DIMENSIONDIR)/src_dimensional_four

## GET_NEXT_LINE ##
SRC_GET_NEXT_LINE_DIR = $(ROOTDIR)/src_get_next_line

## DOUBLY_LIST ##
SRC_DOUBLY_LIST_DIR = $(ROOTDIR)/src_doubly_list

#####***** SRC *****#####

SRC_C_FILE =	ft_bnull.c	\
			ft_error.c	\
			ft_ptrcpy.c	\
			ft_ptrlen.c	\
			ft_split.c

SRC_C = $(addprefix $(SRC_DIR)/, $(SRC_C_FILE))

SRC_IS_C_FILE =	ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c

SRC_IS_C = $(addprefix $(SRC_IS_DIR)/, $(SRC_IS_C_FILE))

SRC_LST_C_FILE =	ft_lst_len.c		\
				ft_lst_malloc.c		\
				ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c

SRC_LST_C = $(addprefix $(SRC_LST_DIR)/, $(SRC_LST_C_FILE))

SRC_MALLOC_C_FILE =	ft_calloc.c		\
					ft_zeromalloc.c

SRC_MALLOC_C = $(addprefix $(SRC_MALLOC_DIR)/, $(SRC_MALLOC_C_FILE))

SRC_MATH_C_FILE =	ft_abs.c					\
					ft_constant_e.c				\
					ft_constant_pi.c			\
					ft_constant_square_root.c	\
					ft_cos.c					\
					ft_cycle.c					\
					ft_max.c					\
					ft_min.c					\
					ft_percent.c				\
					ft_sign.c					\
					ft_sin.c					\
					ft_tan.c


SRC_MATH_C = $(addprefix $(SRC_MATH_DIR)/, $(SRC_MATH_C_FILE))


SRC_MEMORY_C_FILE =	ft_bzero.c		\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_memset.c

SRC_MEMORY_C = $(addprefix $(SRC_MEMORY_DIR)/, $(SRC_MEMORY_C_FILE))

SRC_PUT_C_FILE =	ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c

SRC_PUT_C = $(addprefix $(SRC_PUT_DIR)/, $(SRC_PUT_C_FILE))

SRC_STR_C_FILE = \
				ft_str_diff.c		\
				ft_str_upper.c		\
				ft_strchr_index.c	\
				ft_strchr_num.c		\
				ft_strchr.c			\
				ft_strcmp.c			\
				ft_strcpy.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strmcpy.c		\
				ft_strncmp.c		\
				ft_strncpy.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c

SRC_STR_C = $(addprefix $(SRC_STR_DIR)/, $(SRC_STR_C_FILE))

SRC_TO_C_FILE =	ft_atoi.c			\
				ft_atoi_base.c		\
				ft_atoi_arr.c		\
				ft_atoi_move.c		\
				ft_dtoa.c			\
				ft_etoa.c			\
				ft_itoa_base.c		\
				ft_itoa.c

SRC_TO_C = $(addprefix $(SRC_TO_DIR)/, $(SRC_TO_C_FILE))

## SRC OBJS ##
OBJS =	$(SRC_C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)					\
		$(SRC_IS_C:$(SRC_IS_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_MALLOC_C:$(SRC_MALLOC_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MATH_C:$(SRC_MATH_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MEMORY_C:$(SRC_MEMORY_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_PUT_C:$(SRC_PUT_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_STR_C:$(SRC_STR_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_TO_C:$(SRC_TO_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_LST_C:$(SRC_LST_DIR)/%.c=$(OBJ_DIR)/%.o)

## DIMENSION ##
SRC_AXIS_C_FILE =	ft_axis_controller.c	\
					ft_axis_init.c			\
					ft_axis_view.c

SRC_AXIS_C = $(addprefix $(SRC_AXIS_DIR)/, $(SRC_AXIS_C_FILE))

SRC_DIMENSIONAL_ZERO_C_FILE =	ft_d_zero_new.c

SRC_DIMENSIONAL_ZERO_C = $(addprefix $(SRC_DIMENSIONAL_ZERO_DIR)/, $(SRC_DIMENSIONAL_ZERO_C_FILE))

SRC_DIMENSIONAL_ONE_C_FILE =	ft_d_one_addr.c		\
								ft_d_one_connect.c	\
								ft_d_one_connect1.c	\
								ft_d_one_head.c		\
								ft_d_one_new.c		\
								ft_d_one_switch.c

SRC_DIMENSIONAL_ONE_C = $(addprefix $(SRC_DIMENSIONAL_ONE_DIR)/, $(SRC_DIMENSIONAL_ONE_C_FILE))

SRC_DIMENSIONAL_TWO_C_FILE =	ft_d_two_addr.c		\
								ft_d_two_connect.c	\
								ft_d_two_connect1.c	\
								ft_d_two_connect2.c	\
								ft_d_two_connect_axis_one.c	\
								ft_d_two_connect_axis_two.c	\
								ft_d_two_head.c		\
								ft_d_two_new.c		\
								ft_d_two_switch.c

SRC_DIMENSIONAL_TWO_C = $(addprefix $(SRC_DIMENSIONAL_TWO_DIR)/, $(SRC_DIMENSIONAL_TWO_C_FILE))

SRC_DIMENSIONAL_THREE_C_FILE =	ft_d_three_addr.c		\
								ft_d_three_connect.c	\
								ft_d_three_connect1.c	\
								ft_d_three_connect2.c	\
								ft_d_three_connect3.c	\
								ft_d_three_connect_axis_three.c	\
								ft_d_three_connect_axis_two.c	\
								ft_d_three_head.c		\
								ft_d_three_new.c		\
								ft_d_three_switch.c

SRC_DIMENSIONAL_THREE_C = $(addprefix $(SRC_DIMENSIONAL_THREE_DIR)/, $(SRC_DIMENSIONAL_THREE_C_FILE))

SRC_DIMENSIONAL_FOUR_C_FILE =	ft_d_four_addr.c		\
								ft_d_four_connect.c		\
								ft_d_four_connect1.c	\
								ft_d_four_connect2.c	\
								ft_d_four_connect3.c	\
								ft_d_four_connect4.c	\
								ft_d_four_connect_axis_four.c	\
								ft_d_four_connect_axis_three.c	\
								ft_d_four_connect_axis_three_utils.c	\
								ft_d_four_head.c		\
								ft_d_four_new.c			\
								ft_d_four_switch.c

SRC_DIMENSIONAL_FOUR_C = $(addprefix $(SRC_DIMENSIONAL_FOUR_DIR)/, $(SRC_DIMENSIONAL_FOUR_C_FILE))

## DIMENSION OBJS ##
OBJS_DIMENSION =	$(SRC_AXIS_C:$(SRC_AXIS_DIR)/%.c=$(OBJ_DIR)/%.o)							\
					$(SRC_DIMENSIONAL_ZERO_C:$(SRC_DIMENSIONAL_ZERO_DIR)/%.c=$(OBJ_DIR)/%.o)	\
					$(SRC_DIMENSIONAL_ONE_C:$(SRC_DIMENSIONAL_ONE_DIR)/%.c=$(OBJ_DIR)/%.o)		\
					$(SRC_DIMENSIONAL_TWO_C:$(SRC_DIMENSIONAL_TWO_DIR)/%.c=$(OBJ_DIR)/%.o)		\
					$(SRC_DIMENSIONAL_THREE_C:$(SRC_DIMENSIONAL_THREE_DIR)/%.c=$(OBJ_DIR)/%.o)	\
					$(SRC_DIMENSIONAL_FOUR_C:$(SRC_DIMENSIONAL_FOUR_DIR)/%.c=$(OBJ_DIR)/%.o)

## GET_NEXT_LINE ##
SRC_GET_NEXT_LINE_C_FILE =	ft_get_next_line.c	\
							ft_fd.c				\
							ft_read.c

SRC_GET_NEXT_LINE_C = $(addprefix $(SRC_GET_NEXT_LINE_DIR)/, $(SRC_GET_NEXT_LINE_C_FILE))

## GET_NEXT_LINE OBJS ##
OBJS_GET_NEXT_LINE = $(SRC_GET_NEXT_LINE_C:$(SRC_GET_NEXT_LINE_DIR)/%.c=$(OBJ_DIR)/%.o)

## DOUBLY_LIST ##
SRC_DOUBLY_LIST_C_FILE = ft_doubly_list_add.c		\
						ft_doubly_list_connect.c	\
						ft_doubly_list_head_add.c	\
						ft_doubly_list_head_pop.c	\
						ft_doubly_list.c

SRC_DOUBLY_LIST_C = $(addprefix $(SRC_DOUBLY_LIST_DIR)/, $(SRC_DOUBLY_LIST_C_FILE))

## DOUBLY_LIST OBJS ##
OBJS_DOUBLY_LIST = $(SRC_DOUBLY_LIST_C:$(SRC_DOUBLY_LIST_DIR)/%.c=$(OBJ_DIR)/%.o)

## OBJS_CLEAN ##
OBJS_CLEAN = $(OBJS) $(OBJS_GET_NEXT_LINE) $(OBJS_DIMENSION)  $(OBJS_DOUBLY_LIST)

#####***** working *****#####

all : $(OBJ_DIR) $(TARGET) 

bonus : $(OBJ_DIR) $(TARGET)

$(TARGET) : $(OBJS) $(OBJS_GET_NEXT_LINE) $(OBJS_DIMENSION) $(OBJS_DOUBLY_LIST)
	@ar src $@ $^
	@echo "$(FG_MAGENTA)ar $(FG_LBLUE)src $(FG_LYELLOW)$@$(FG_LCYAN)"
	@(for i in $(OBJS) $(OBJS_GET_NEXT_LINE) $(OBJS_DIMENSION); do echo $$i; done)
	@echo "$(FG_WHITE)"

$(OBJ_DIR) : 
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_IS_DIR)/%.c 
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MALLOC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MATH_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MEMORY_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PUT_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_STR_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_TO_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_LST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

## DIMENSION ##
$(OBJ_DIR)/%.o : $(SRC_AXIS_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIMENSIONAL_ZERO_DIR)/%.c 
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIMENSIONAL_ONE_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIMENSIONAL_TWO_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIMENSIONAL_THREE_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIMENSIONAL_FOUR_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

## GET_NEXT_LINE ##
$(OBJ_DIR)/%.o : $(SRC_GET_NEXT_LINE_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

## DOUBLY_LIST ##
$(OBJ_DIR)/%.o : $(SRC_DOUBLY_LIST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@



clean : 
	@rm -f $(OBJS_CLEAN)
	@(for F in $(OBJS_CLEAN); do echo $$F; done)

fclean : OBJS_CLEAN+=$(ROOTDIR)/$(TARGET)
fclean : clean

re : fclean all

.PHONY: all bonus clean fclean re
