CC = g++ -Wall -Wextra -Werror

SRC = main.cpp \
	animal.cpp \
	dog.cpp\
	cat.cpp\
	duck.cpp\
	pig.cpp\
	bee.cpp

HEADERS = $(wildcard *.hpp)
NAME = zoo

zoo : ${SRC} ${HEADERS}
	g++ ${SRC} -o ${NAME} -std=c++11

clean :
	rm -f ${NAME}
