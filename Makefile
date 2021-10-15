CC = g++

SOURCES = main.cpp MyShared_ptr.cpp

all:
	$(CC) $(SOURCES) -o main

run:
	@./main

clean:
	@rm -rf *.o main