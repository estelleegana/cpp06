#nom de l'executable
NAME = ex00

#compilateur
CC = c++

#flags
FLAGS = -Wall -Wextra -Werror -std=c++98

#fichiers sources
SRCS = ScalarConverter.cpp \
	main.cpp \

#creation d'objets a partir des fichiers sources
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

#compilations
all: $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all