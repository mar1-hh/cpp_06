NAME = convert

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp

OBJ_SRCS = ${SRCS:.cpp=.o}


all: ${NAME}

${NAME}: ${OBJ_SRCS}
	${CC} ${CPPFLAGS} $^ -o $@

%.o: %.cpp ScalarConverter.hpp
	${CC} ${CPPFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_SRCS}

fclean: clean
	rm -f ${NAME}

re: fclean all