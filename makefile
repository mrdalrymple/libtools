INCLUDE = include
SOURCE = source
BIN = bin
NAME = libtools
CC = g++

default: all
	
all: log.o
	ar rvs $(NAME).a *.o
	mkdir -p $(BIN)
	mv $(NAME).a $(BIN)
	mv *.o $(BIN)

log.o: 
	$(CC) -o log.o -c $(SOURCE)/log.cpp -I$(INCLUDE)

clean:
	rm -f *.o
	rm -f $(NAME).a
	rm -f $(BIN)/*.o
	rm -f $(BIN)/$(NAME).a
	rm -f -d $(BIN)
