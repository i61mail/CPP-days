CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

NAME = ./a.out

EXEC_MAN = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp \


OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ_MAN) -o $(NAME)

clean : 
	rm -f $(OBJ_MAN)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean