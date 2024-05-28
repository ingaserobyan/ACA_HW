CC = g++
CFLAGS = -std=c++11 -Wall

SOURCES := $(wildcard *.cpp)
EXECUTABLE = printFile

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
