# https://gl.developpez.com/tutoriel/outil/makefile/
# section 7, avec modifications (.c -> .cpp)

CC=g++
CFLAGS= -Wall -std=c++14 -I/home/bib/lib/SFML-2.4.2/include
LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
EXEC=Main.out
SRC= $(wildcard *.cpp)
HEADERS= $(wildcard *.h)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
	rm -f $(EXEC)
