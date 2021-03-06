CK_NAME = checker
PS_NAME = push_swap
OS = $(shell uname)

SRCDIR = ./srcs
INCDIR = ./includes
CK_OBJDIR = ./ck_obj
PS_OBJDIR = ./ps_obj

CK_SRC = 	checker.c \
					pile.c \
					pile_utils.c \
					exit.c \
					exec.c \
					checkerror.c \
					arg.c \

PS_SRC = 	push_swap.c \
					pile.c \
					pile_utils.c \
					exit.c \
					exec.c \
					checkerror.c \
					arg.c \
					swap_utils.c \
					best_moveA.c \

CK_OBJ		= $(addprefix $(CK_OBJDIR)/,$(CK_SRC:.c=.o))
PS_OBJ		= $(addprefix $(PS_OBJDIR)/,$(PS_SRC:.c=.o))

CC		= gcc
CFLAGS = -Wall -Wextra -Werror

FTDIR = ./libft
FT_LIB = $(addprefix $(FTDIR)/,libft.a)
FT_INC = -I $(FTDIR)
FT_LNK = -L $(FTDIR) -l ft

all: 	obj objs $(FT_LIB) $(CK_NAME) $(PS_NAME)

obj:
		@mkdir -p $(CK_OBJDIR)

objs:
		@mkdir -p $(PS_OBJDIR)

$(CK_OBJDIR)/%.o:$(SRCDIR)/%.c
		@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(PS_OBJDIR)/%.o:$(SRCDIR)/%.c
		@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FTDIR)

$(CK_NAME): $(CK_OBJ)
		@$(CC) $(CFLAGS) $(CK_OBJ) $(FT_LNK) -lm -o $(CK_NAME)

$(PS_NAME): $(PS_OBJ)
		@$(CC) $(CFLAGS) $(PS_OBJ) $(FT_LNK) -lm -o $(PS_NAME)

clean:
		rm -rf $(CK_OBJDIR)
		rm -rf $(PS_OBJDIR)
		make -C $(FTDIR) clean

fclean: clean
		rm -f $(CK_NAME)
		rm -f $(PS_NAME)
		make -C $(FTDIR) fclean

re: fclean all
