NAME = pipex

CC = cc

# CFLAGS = -Wall -Werror -Wextra

CFLAGS = -g3
SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/

# SRC = main.c
SRCS = $(addprefix $(DSRC),\
		check_args.c		\
		check_permission.c	\
		error.c				\
		get_bin.c			\
		get_path.c			\
		main.c				\
		path_cmd.c			\
		free.c				\
		split.c				\
		exec.c\
		utils.c)

# SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ = ${SRCS:.c=.o}

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

all : $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re