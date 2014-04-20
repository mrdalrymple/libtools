INCLUDE = include
SOURCE = source
BIN = bin
NAME = libtools
CC = g++ -std=c++11

default: all
	
all: log.o variant.o string.o
	@ar rvs $(NAME).a *.o > /dev/null 2>&1
	@mkdir -p $(BIN)
	@mv $(NAME).a $(BIN)
	@mv *.o $(BIN)

log.o: 
	@$(CC) -o log.o -c $(SOURCE)/generic/log.cpp -I$(INCLUDE)
	
variant.o:
	@$(CC) -o variant.o -c $(SOURCE)/generic/variant.cpp -I$(INCLUDE)
	
string.o:
	@$(CC) -o string.o -c $(SOURCE)/string/string.cpp -I$(INCLUDE)

clean:
	@rm -f *.o
	@rm -f $(NAME).a
	@rm -f $(BIN)/*.o
	@rm -f $(BIN)/$(NAME).a
	@rm -f -d $(BIN)

#test:
#	@make -f test/makefile
#	
#test-run:
#	@make -f test/makefile run
#	
#test-clean:
#	@make -f test/makefile clean
