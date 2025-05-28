CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -L. -lraylib -lgdi32 -lwinmm

all: dashboard

dashboard: dashboard.cpp
	$(CXX) dashboard.cpp -o dashboard $(CXXFLAGS) $(LDFLAGS)

clean:
	del dashboard.exe 