CC = c++

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -std=c++98

NAME = phonebook

EXEC_MAN = ./main.cpp ./Contact.cpp ./PhoneBook.cpp

OBJ_MAN = ${EXEC_MAN:.cpp=.o}

%.o : %.cpp PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ_MAN) -o $(NAME)

clean : 
	rm -f $(OBJ_MAN)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
