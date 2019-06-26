##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compilation
##

LIB_PATH	=	./lib/my

SRC_NM	=	src/nm/main.c \
			src/nm/nm.c \
			src/nm/init_file.c \
			src/nm/arch64.c \
			src/nm/arch32.c \
			src/nm/sort32.c \
			src/nm/sort64.c \
			src/nm/utils.c

SRC_OBJDUMP	=	src/objdump/main.c \
				src/objdump/objdump.c \
				src/objdump/init_file.c \
				src/objdump/arch64.c \
				src/objdump/arch32.c \
				src/objdump/print64.c \
				src/objdump/print32.c \
				src/objdump/utils.c

SRC_test	= 	tests/test.c

OBJ_NM		=	$(SRC_NM:.c=.o)

OBJ_OBJDUMP	=	$(SRC_OBJDUMP:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -g

LDFLAG		=	-lcriterion -lgcov

NAME_NM	=	my_nm

NAME_OBJDUMP	=	my_objdump

all: $(NAME_NM) $(NAME_OBJDUMP)

nm: $(NAME_NM)

objdump: $(NAME_OBJDUMP)

$(NAME_NM): $(OBJ_NM)
	@gcc $(OBJ_NM) -o $(NAME_NM) $(CFLAGS) -I./include

$(NAME_OBJDUMP): $(OBJ_OBJDUMP)
	@gcc $(OBJ_OBJDUMP) -o $(NAME_OBJDUMP) $(CFLAGS) -I./include

tests_run:
	cc -o units $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	./units

clean:
	rm -f $(OBJ_NM) $(OBJ_OBJDUMP) *.gcno *.gcda

fclean: clean
	rm -f $(NAME_NM) $(NAME_OBJDUMP)

re: fclean all
