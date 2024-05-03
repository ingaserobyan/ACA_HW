CC = g++ -Wall -Wextra -Werror

NAME = chess

SRC = main.cpp \
	piece.cpp\
	pawn.cpp\
	knight.cpp\
	rook.cpp\
	queen.cpp\
	king.cpp\
	bishop.cpp

HEADERS = $(wildcard *.hpp)

${NAME} : ${SRC} ${HEADERS}
	${CC} ${SRC} -o ${NAME} -std=c++11

clear :
	rm -f clean ${NAME}
