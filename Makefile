CXX_FLAGS=-W -Wall -Werror -Wno-unused-function
GTEST_LIBS=-lgtest_main -lgtest -lpthread

TARGET=test_powermod

.PHONY: all clean runtest

all: $(TARGET)

clean:
	rm -rf *.o *~ $(TARGET)

runtest: all
	./test_powermod

test_powermod: test_powermod.cpp powermod.c
	g++ $(CXX_FLAGS) $(GTEST_LIBS) -o $@ $^

