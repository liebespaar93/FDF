# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 10:50:03 by kyoulee           #+#    #+#              #
#    Updated: 2022/09/13 08:36:37 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# option
# m1 : 맥에서 사용가능하게 mms 라이브러리를 불러옴
# linux : 아직 만들지 않음 컴파일 단걔 LDLIBS 추가 변경 요구함
# **************************************************************************** #

TARGET = fdf

CC = cc
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
DFLAGS = $(NULL)
IFLAGS =								\
	-I $(INCLUDE_DIR)					\
	-I $(INCLUDE_LIBFT_DIR)				\
	-I $(INCLUDE_FT_PRINTF_DIR)			\
	-I $(INCLUDE_MINILIBX_SELECT_DIR)	\
	-I $(INCLUDE_MLX_DIR)
LDFLAGS =						\
	-L $(LIBFT_DIR)				\
	-L $(FT_PRINTF_DIR)			\
	-L $(MINILIBX_SELECT_DIR)
LDLIBS =											\
	-lft											\
	-lftprintf										\
	-lmlx -lm -framework OpenGL -framework AppKit

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

#####***** DIR *****#####

ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
SRC_DIR = $(ROOTDIR)/src
SRC_FDF_DIR = $(ROOTDIR)/src_fdf
SRC_MLX_DIR = $(ROOTDIR)/src_mlx
SRC_MLX_BASIS_DIR = $(SRC_MLX_DIR)/src_basis
SRC_MLX_DRAW_DIR = $(SRC_MLX_DIR)/src_draw
SRC_MLX_LOOP_DIR = $(SRC_MLX_DIR)/src_loop
SRC_MLX_MATRIX_DIR = $(SRC_MLX_DIR)/src_matrix
SRC_MLX_COLOR_DIR = $(SRC_MLX_DIR)/src_mlx_color
SRC_MLX_KEYBOARD_DIR = $(SRC_MLX_DIR)/src_mlx_keyboard
SRC_MLX_MOUSE_DIR = $(SRC_MLX_DIR)/src_mlx_mouse
SRC_MLX_PARAM_DIR = $(SRC_MLX_DIR)/src_param
SRC_MLX_POLYGON_DIR = $(SRC_MLX_DIR)/src_polygon
SRC_MLX_SCREAN_DIR = $(SRC_MLX_DIR)/src_screan
SRC_MLX_VECTOR_DIR = $(SRC_MLX_DIR)/src_vector

OBJ_DIR = $(ROOTDIR)/obj
INCLUDE_DIR = $(ROOTDIR)/include
INCLUDE_MLX_DIR = $(SRC_MLX_DIR)/include
## MODULES ##
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = $(ROOTDIR)/modules/Libft
INCLUDE_LIBFT_DIR = $(LIBFT_DIR)/include

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_DIR = $(ROOTDIR)/modules/ft_printf
INCLUDE_FT_PRINTF_DIR = $(FT_PRINTF_DIR)/include

MINILIBX_DIR = $(ROOTDIR)/modules/minilibx

ifneq ($(filter m1, $(MAKECMDGOALS)), )
MINILIBX_SELECT = $(MINILIBX_MMS)
MINILIBX_SELECT_DIR = $(MINILIBX_MMS_DIR)
INCLUDE_MINILIBX_SELECT_DIR = $(INCLUDE_MINILIBX_MMS_DIR)
MINILIBX_SELECT_CLEAN = clean_minilibx_mms
else
MINILIBX_SELECT = $(MINILIBX_MACOS)
MINILIBX_SELECT_DIR = $(MINILIBX_MACOS_DIR)
INCLUDE_MINILIBX_SELECT_DIR = $(INCLUDE_MINILIBX_MACOS_DIR)
MINILIBX_SELECT_CLEAN = clean_minilibx_macos
endif

MINILIBX_MACOS = $(MINILIBX_MACOS_DIR)/libmlx.a
MINILIBX_MACOS_DIR = $(MINILIBX_DIR)/minilibx_macos
INCLUDE_MINILIBX_MACOS_DIR = $(MINILIBX_MACOS_DIR)

MINILIBX_MMS = $(MINILIBX_MMS_DIR)/libmlx.dylib
MINILIBX_MMS_DIR = $(MINILIBX_DIR)/minilibx_mms_20191025_beta
INCLUDE_MINILIBX_MMS_DIR = $(MINILIBX_MMS_DIR)

#####***** SRC *****#####
SRC_C_SRC =	main.c\
			ft_fdf_ply_prim.c\
			ft_fdf_ply_v3.c\
			ft_fdf_ply.c

SRC_C = $(addprefix $(SRC_DIR)/, $(SRC_C_SRC))

SRC_FDF_C_SRC = 

SRC_FDF_C = $(addprefix $(SRC_FDF_DIR)/, $(SRC_FDF_C_SRC))

SRC_MLX_BASIS_C_SRC = ft_basis2.c

SRC_MLX_BASIS_C = $(addprefix $(SRC_MLX_BASIS_DIR)/, $(SRC_MLX_BASIS_C_SRC))

SRC_MLX_DRAW_C_SRC = ft_backbuffer.c	\
					ft_draw.c			\
					ft_scanline.c

SRC_MLX_DRAW_C = $(addprefix $(SRC_MLX_DRAW_DIR)/, $(SRC_MLX_DRAW_C_SRC))

SRC_MLX_LOOP_C_SRC = ft_loop.c

SRC_MLX_LOOP_C = $(addprefix $(SRC_MLX_LOOP_DIR)/, $(SRC_MLX_LOOP_C_SRC))

SRC_MLX_MATRIX_C_SRC = 	ft_matrix_2_mult.c	\
						ft_matrix_2.c		\
						ft_matrix_3_mult.c	\
						ft_matrix_3.c		\
						ft_matrix_4_mult.c	\
						ft_matrix_4_rotation.c	\
						ft_matrix_4.c

SRC_MLX_MATRIX_C = $(addprefix $(SRC_MLX_MATRIX_DIR)/, $(SRC_MLX_MATRIX_C_SRC))

SRC_MLX_COLOR_C_SRC = ft_mlx_color.c

SRC_MLX_COLOR_C = $(addprefix $(SRC_MLX_COLOR_DIR)/, $(SRC_MLX_COLOR_C_SRC))

SRC_MLX_KEYBOARD_C_SRC = ft_mac_key_down.c	\
							ft_mac_key_hold.c	\
							ft_mac_key_up.c	\
							ft_mac_keyboard.c

SRC_MLX_KEYBOARD_C = $(addprefix $(SRC_MLX_KEYBOARD_DIR)/, $(SRC_MLX_KEYBOARD_C_SRC))

SRC_MLX_MOUSE_C_SRC = ft_mac_mouse_down.c	\
						ft_mac_mouse_drag.c	\
						ft_mac_mouse_up.c	\
						ft_mac_mouse.c

SRC_MLX_MOUSE_C = $(addprefix $(SRC_MLX_MOUSE_DIR)/, $(SRC_MLX_MOUSE_C_SRC))

SRC_MLX_PARAM_C_SRC = ft_param.c

SRC_MLX_PARAM_C = $(addprefix $(SRC_MLX_PARAM_DIR)/, $(SRC_MLX_PARAM_C_SRC))

SRC_MLX_POLYGON_C_SRC = ft_polygon_transform.c	\
						ft_polygon.c		\
						ft_primitive.c

SRC_MLX_POLYGON_C = $(addprefix $(SRC_MLX_POLYGON_DIR)/, $(SRC_MLX_POLYGON_C_SRC))

SRC_MLX_SCREAN_C_SRC = ft_screan.c

SRC_MLX_SCREAN_C = $(addprefix $(SRC_MLX_SCREAN_DIR)/, $(SRC_MLX_SCREAN_C_SRC))

SRC_MLX_VECTOR_C_SRC = ft_vector_2.c	\
						ft_vector_3.c	\
						ft_vector_to.c

SRC_MLX_VECTOR_C = $(addprefix $(SRC_MLX_VECTOR_DIR)/, $(SRC_MLX_VECTOR_C_SRC))


OBJS =	$(SRC_C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_FDF_C:$(SRC_FDF_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_BASIS_C:$(SRC_MLX_BASIS_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_DRAW_C:$(SRC_MLX_DRAW_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_LOOP_C:$(SRC_MLX_LOOP_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_MATRIX_C:$(SRC_MLX_MATRIX_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_COLOR_C:$(SRC_MLX_COLOR_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_KEYBOARD_C:$(SRC_MLX_KEYBOARD_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_MOUSE_C:$(SRC_MLX_MOUSE_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_PARAM_C:$(SRC_MLX_PARAM_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_POLYGON_C:$(SRC_MLX_POLYGON_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_SCREAN_C:$(SRC_MLX_SCREAN_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_VECTOR_C:$(SRC_MLX_VECTOR_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJS_CLEAN = $(OBJS)

#####***** working *****#####

all : $(OBJ_DIR) $(TARGET)

bonus : $(OBJ_DIR) $(TARGET)

$(TARGET) : $(OBJS) $(LIBFT) $(MINILIBX_SELECT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(TARGET)
	@echo "$(FG_LMAGENTA)$(CC) $(FG_BLUE) $(CFLAGS)"
	@(for i in $(IFLAGS) $(LDFLAGS); do echo $$i; done)
	@echo "$(LDLIBS) $(FG_LCYAN)"
	@(for i in $(OBJS); do echo $$i; done)
	@echo "$(FG_BLUE)-o $(FG_LYELLOW)$(TARGET)$(NO_COLOR)"

$(OBJ_DIR) : 
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_FDF_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_BASIS_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_DRAW_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_LOOP_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_MATRIX_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_COLOR_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_KEYBOARD_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_MOUSE_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_PARAM_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_POLYGON_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_SCREAN_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_VECTOR_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

debug : 
	$(CC) main.c $(CFLAGS) $(IFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -g3 -fsanitize=address
	
## MODULES ##
$(LIBFT):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)Libft$(NO_COLOR) -> $(FG_LCYAN)$(LIBFT)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "$(NO_COLOR)"

$(FT_PRINTF):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)ft_printf$(NO_COLOR) -> $(FG_LCYAN)$(FT_PRINTF)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(FT_PRINTF_DIR) bonus
	@echo "$(NO_COLOR)"

$(MINILIBX_MACOS):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)minilibx_macos$(NO_COLOR) -> $(FG_LCYAN)$(MINILIBX_MACOS)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(MINILIBX_MACOS_DIR)
	@echo "$(NO_COLOR)"

$(MINILIBX_MMS):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)minilibx_mms$(NO_COLOR) -> $(FG_LCYAN)$(MINILIBX_MMS)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(MINILIBX_MMS_DIR)
	cp $(MINILIBX_MMS) $(ROOTDIR)/
	@echo "$(NO_COLOR)"

#####***** clean *****#####

## MODULES ##
clean_libft :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(LIBFT))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(LIBFT_DIR) $(MODULE_CLEAN)
	@echo "$(NO_COLOR)"

clean_ft_printf :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(FT_PRINTF))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(FT_PRINTF_DIR) $(MODULE_CLEAN)
	@echo "$(NO_COLOR)"

clean_minilibx_macos :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(MINILIBX_SELECT))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(MINILIBX_SELECT_DIR) clean 
	@echo "$(NO_COLOR)"

clean_minilibx_mms :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(MINILIBX_SELECT))$(NO_COLOR)$(BG_MAKE1)"
	rm -f $(ROOTDIR)/$(notdir $(MINILIBX_MMS))
	$(MAKE) -C $(MINILIBX_MMS_DIR) clean 
	@echo "$(NO_COLOR)"

MODULE_CLEAN = clean

clean : clean_libft clean_ft_printf $(MINILIBX_SELECT_CLEAN)
	rm -f $(OBJS_CLEAN)

fclean : OBJS_CLEAN+=$(TARGET)
fclean : MODULE_CLEAN=fclean
fclean : clean

re : fclean all

.PHONY: all re  clean fclean clean_libft clean_minilibx_macos cleanminilibx_mms m1
