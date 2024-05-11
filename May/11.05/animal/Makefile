CC = g++ -Wall -Wextra -Werror
SRC = 	animal.cpp \
	dog.cpp\
	cat.cpp\
	duck.cpp\
	pig.cpp\
	bee.cpp
	
OBJ = $(SRC:.cpp=.o)
HEADERS = $(wildcard *.hpp)
LIB = zoo.lib

%.o : %.cpp $(HEADERS)
	$(CC) -c $< -o $@

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

zoo :
	$(CC) main.cpp -o zoo -L. -lzoo -std=c++11

fclean :
	rm -f $(LIB) $(OBJ) zoo

clean:
	rm -f $(OBJ)
