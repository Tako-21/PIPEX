NAME = pipex

CC = cc

# CFLAGS = -Wall -Werror -Wextra

CFLAGS = -g3 -Wall
SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/

# SRC = main.c
SRCS = $(addprefix $(DSRC),\
		error.c				\
		get.c				\
		here_doc.c			\
		main.c				\
		get_next_line.c		\
		list.c				\
		split.c				\
		utils.c				\
		utils2.c)

# SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ = ${SRCS:.c=.o}

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

all : directories $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "\n"
		@echo "Compiling done"

directories :
	@mkdir -p $(OBJ_PATH)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
