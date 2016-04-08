CC	= 				gcc

STATIC = 			libmy_printf_`uname -m`-`uname -s`.a

DYNAMIC = 			libmy_printf_`uname -m`-`uname -s`.so

SRC  = 				my_printf.c     \
  					fonctions.c    	\
     				echo.c 			\
     				fonctions2.c 	\
     				echo2.c

OBJ = 				$(SRC:%.c=%.o)
RM = 				rm -f
CFLAGS = 			-fPIC -W -Wall -Wextra -Werror -g -I.
CFLAG = 			-shared

.PHONY : 			make my_printf_static my_printf_dynamic all clean fclean re

make: 				all

my_printf_static:	$(OBJ)
					ar r $(STATIC) $(OBJ)

my_printf_dynamic:	$(OBJ)
					$(CC) $(CFLAGS) $(CFLAG) -o $(DYNAMIC) $(SRC)

all:				my_printf_static my_printf_dynamic

clean:
					$(RM) $(OBJ)

fclean:				clean
					$(RM) $(STATIC) $(DYNAMIC) a.out

re:					fclean all