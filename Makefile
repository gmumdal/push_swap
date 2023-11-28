NAME = push_swap
BONUS = checker
SRC_DIR = srcs
SRCS = push_swap.c error_check.c stack.c \
	command.c sorting.c hard_sorting.c \
	division.c tri_check.c merge.c \
	division_in_a.c merge_utils.c
SRCS_B = push_swap_bonus.c error_check_bonus.c stack_bonus.c command_bonus.c
INC_DIR = incs
INCS = push_swap.h
INCS_B = push_swap_bonus.h
LIBFT = -Ilibft -Llibft -lft
LIBFT_DIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(addprefix $(SRC_DIR)/, $(SRCS)) $(addprefix $(INC_DIR)/, $(INCS))
	make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(addprefix $(SRC_DIR)/, $(SRCS)) -I$(INC_DIR) $(LIBFT)

clean :
	make -sC $(LIBFT_DIR) fclean

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUS)
	
$(BONUS) : $(addprefix $(SRC_DIR)/, $(SRCS_B)) $(addprefix $(INC_DIR)/, $(INCS_B))
	make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(addprefix $(SRC_DIR)/, $(SRCS_B)) -I$(INC_DIR) $(LIBFT)

.PHONY : all clean fclean re bonus
