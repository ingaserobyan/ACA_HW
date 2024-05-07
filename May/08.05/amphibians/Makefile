CC = g++ -Wall -Wextra -Werror

NAME = amphibian

SRC = animal.cpp\
	fish.cpp\
	mammals.cpp\
	amphibian.cpp\
	main.cpp

HEADERS = $(wildcard *.hpp)

${NAME} : ${SRC} ${HEADERS}
	${CC} ${SRC} -o ${NAME} -std=c++11

clear :
	rm -f clean ${NAME}
