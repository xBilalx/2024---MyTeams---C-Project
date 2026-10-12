##
## EPITECH PROJECT, 2024
## my_ftp
## File description:
## Makefile
##

SRC		=	src/client/commandes/*.c \
			src/client/*.c

SRC_SERV	= 	./src/server/*.c	\
				./src/server/features/*.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	myteams_server
NAME2	=	myteams_cli

LIB		=	-L ./libs/myteams/ -l myteams

FLAG	=	-I include -g3 -luuid

all:	server client

$(NAME):
			gcc $(SRC) -I include -o $(NAME) -g3

server:
			gcc $(SRC_SERV) -o $(NAME) $(LIB) $(FLAG)
client:
			gcc $(SRC) -o $(NAME2) $(LIB) $(FLAG)
clean:
			rm -f *.o $(OBJ)

fclean:	clean
			rm -f $(NAME)
			rm -f $(NAME2)

re:			fclean all
