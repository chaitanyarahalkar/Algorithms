CC=g++
CFLAGS=-Wall
.SUFFIXES = .cpp
objs:=$(wildcard *.cpp)
targets:=$(objs:.cpp= )

.PHONY:all
all: $(targets)
.cpp:
	$(CC) $(CFLAGS) -std=c++11 -o $@ $< 

clean:
all:
	rm  $<
