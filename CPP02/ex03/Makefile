CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = bsp

EXEC_MAN = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp Fixed.hpp Point.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ_MAN) -o $(NAME)

clean : 
	rm -f $(OBJ_MAN)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)