CC = g++ -Wall -Wextra -Werror

SRC = main.cpp \
	array.cpp

HEADERS = $(wildcard *.hpp)
NAME = array

{NAME} : ${SRC} ${HEADERS}
	g++ ${SRC} -o ${NAME} -std=c++11

clean :
	rm -f ${NAME}
