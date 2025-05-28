CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -L. -lraylib -lgdi32 -lwinmm

all: main

main: main.cpp
	$(CXX) main.cpp -o main $(CXXFLAGS) $(LDFLAGS)

clean:
	del main.exe 