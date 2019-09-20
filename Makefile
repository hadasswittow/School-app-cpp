include .depends
CC=g++
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi
CXXFLAGS=$(CFLAGS)
TARGET=main
LDFLAGS=-g
INC_FLAGS=-I../include
CFLAGS=-pedantic -Wall -Werror -Wconversion -ansi -g $(INC_FLAGS)
# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

.PHONY: clean run gdb

$(TARGET): $(OBJS)

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	valgrind ./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)






