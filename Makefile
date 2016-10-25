CC:=g++
FLAG:=-std=c++11 -Wall
OBJSDIR:=_build

SRCS:=$(filter-out main.cpp,$(wildcard *.cpp))
OBJS:=$(patsubst %.cpp,%.o,$(SRCS))

main: main.cpp $(OBJS)
	$(CC) $(FLAG) main.cpp $(OBJS) -o main.exe

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf main.exe *.o

