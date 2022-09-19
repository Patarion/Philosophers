NAME = philo

SRCS = Actions.c Erreur.c Main.c Parsing.c Time.c

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
NORM = norminette
RM = rm -f

all: $(NAME)

$(NAME):

philo :
		${CC} ${CFLAGS} ${SRCS} -o philo
		@echo "____Philo créé avec succès____"

clean:
		${RM} philo
		@echo "____L'exécutable a été supprimé____"
fclean: clean

re: fclean all

.PHONY: all clean fclean re