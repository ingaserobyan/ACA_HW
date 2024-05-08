CC = g++

NAME = functor

SRC = A.cpp\
	main.cpp

HEADERS = $(wildcard *.hpp)

${NAME} : ${SRC} ${HEADERS}
	${CC} ${SRC} -o ${NAME}

clear :
	rm -f clean ${NAME}
