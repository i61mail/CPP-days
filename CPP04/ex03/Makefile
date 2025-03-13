CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ./a.out

EXEC_MAN = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp \
			Character.cpp MateriaSource.cpp Ice.cpp Cure.cpp

OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp Character.hpp MateriaSource.hpp Ice.hpp Cure.cpp
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