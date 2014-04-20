GTEST = gtest-1.7.0
GTEST_INCLUDE = $(GTEST)/include
GTEST_LIBRARY = $(GTEST)/lib

LIBUT_NAME = tools

LIBUT_LOC = ..
LIBUT_LIBRARY = $(LIBUT_LOC)/bin
LIBUT_INCLUDE = $(LIBUT_LOC)/include

TEST_SOURCE = source
TEST_BIN = bin

OUT = libtools_unittest
CC = g++ -std=c++11

default: all
	
all: $(OUT)
	@mkdir -p $(TEST_BIN)
	@mv -f $(OUT) $(TEST_BIN)

$(OUT):
	@$(CC) $(TEST_SOURCE)/*.cpp -I$(LIBUT_INCLUDE) -I$(GTEST_INCLUDE) \
		-L$(LIBUT_LIBRARY) -L$(GTEST_LIBRARY) -lgtest_main -l$(LIBUT_NAME) -lpthread \
		-o $(OUT)
		
run:
	@./$(TEST_BIN)/$(OUT)

clean:
	@rm -f *.o
	@rm -f $(OUT).a
	@rm -f $(TEST_BIN)/*.o
	@rm -f $(TEST_BIN)/$(OUT)
	@rm -f -d $(TEST_BIN)


