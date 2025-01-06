CC = c++

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -std=c++98

NAME = Account

EXEC_MAN = Account.cpp tests.cpp

OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp Account.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ_MAN) -o $(NAME)

clean : 
	rm -f $(OBJ_MAN)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
