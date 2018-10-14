##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_runner
##

CC		=	gcc -W -Wall -Wextra -Werror
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h

LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	my_putstr_fd.c		\
			my_puterror.c		\
			my_strncpy.c		\
			my_putchar.c		\
			my_strlen.c		\
			my_str_isnum.c		\
			my_getnbr.c		\
			my_put_nbr.c		\
			my_putcharx_fd.c	\
			my_strcmp.c		\
			my_memset.c

LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
NAME		=	navy
LDFLAGS		=	-L./lib
LIBFLAG		=	-lmy
SRC		=	src/board/init.c			\
			src/board/debug.c			\
			src/ext/my_arg_exists.c			\
			src/board/access.c			\
			src/msg/help_msg.c			\
			src/argparse/argparse.c			\
			src/signals/query.c			\
			src/signals/bit_processing.c		\
			src/signals/coords_processing.c		\
			src/signals/com_interface.c		\
			src/signals/com_interface_act.c		\
			src/signals/com_interface_act2.c	\
			src/signals/com_interface_sig.c		\
			src/signals/com_interface_debug.c	\
			src/signals/debug.c			\
			src/game/setup.c			\
			src/game/setup_as.c			\
			src/parsing/board_map_boat.c		\
			src/parsing/parse_file.c		\
			src/board/display.c

MAIN		=	src/main.c

OBJ		=	$(SRC:.c=.o)
OBJ		+=	$(MAIN:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	tests/board_mapping.c		\
			tests/incorrect_parsing.c	\
			tests/game_init.c		\
			tests/file_parsing.c		\
			tests/argchecks.c		\
			tests/file_parsing2.c		\
			tests/get_idx_from_coords.c	\
			tests/retrieve_idx_from_bits.c	\
			tests/ext/test_board_map_boat.c	\
			tests/ext/test_fail.c		\
			tests/ext/my_strtablen.c	\
			tests/redirect_all_std.c
TCFLAGS		=	-I./tests/include
TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	tests/main.c
GDB_NAME	=	gdb.out


.PHONY: tclean gclean cclean lclean lfclean $(NAME)

all:	$(NAME)

#	Library rules
lib:	libh liba

libh:
	@mkdir -p $(LIB_DIR)/$(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

liba:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

re: libfclean lib

#	Program rules

$(NAME): lib
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LIBFLAG)
re: clean fclean $(NAME)

clean:
	$(RM) $(OBJ)

cclean:	clean
	$(RM) $(HDTGR)
	$(RM) $(LIBTGR)
	$(RM) $(NAME)

#	Tests rules
gdb:	gclean lib
	$(DBCC) $(CFLAGS) $(LDFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC)	\
		$(LIB_SRC) $(LDLIBS) $(LIBFLAG)

gclean:
	$(RM) $(GDB_NAME)

tests_run:
	$(CC) $(TCFLAGS) $(CFLAGS) -o $(TEST_NAME) $(TEST_SRC) $(SRC)	\
		$(LIB_SRC) $(TEST_FLAGS)
	./$(TEST_NAME)

tclean:
	$(RM) *.gc*
	$(RM) $(TEST_NAME)

fclean: tclean gclean cclean libfclean
