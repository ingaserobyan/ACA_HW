CC = g++ -Wall -Wextra -Werror -std=c++11
SRC = 	animal.cpp \
	dog.cpp\
	cat.cpp\
	duck.cpp\
	pig.cpp\
	bee.cpp\
	zoo.cpp

OBJ = $(SRC:.cpp=.o)
HEADERS = $(wildcard *.hpp)
LIB = zoo.lib

%.o : %.cpp $(HEADERS)
	$(CC) -c $< -o $@

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

zoo : zoo.lib
	$(CC) main.cpp zoo.lib -o zoo  -std=c++11

fclean :
	rm -f $(LIB) $(OBJ) zoo

clean:
	rm -f $(OBJ)
