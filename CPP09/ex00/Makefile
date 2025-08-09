CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ./btc

EXEC_MAN = main.cpp BitcoinExchange.cpp 

OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp BitcoinExchange.hpp
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