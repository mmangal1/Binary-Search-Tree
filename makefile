#variable for the compiler to use
CP = g++ -std=c++11
CFlag = -g -c
SOURCES = lab7.cpp BSTree.cpp
OBJECTS = lab7.o BSTree.o
PRJ = lab7

all: lab7

$(PRJ): $(OBJECTS)
	$(CP) $(OBJECTS) -o $(PRJ)

$(PRJ).o: $(PRJ).cpp  
	$(CP) $(CFlag) $(PRJ).cpp -o $(PRJ).o

BSTree.o: BSTree.cpp BSTree.h
	$(CP) $(CFlag) BSTree.cpp -o BSTree.o

clean:
	rm *.o $(PRJ)

run: all
	./$(PRJ)

checkmem: all
	valgrind ./$(PRJ) --leak-check=full
