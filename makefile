CXX = g++
CXXFLAGS = -std=c++17

all:
	$(CXX) src/*.cpp -o ms.o

debug:
	$(CXX) src/*.cpp -g -o ms.o
