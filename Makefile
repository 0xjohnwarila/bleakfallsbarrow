CXX=g++
CXXFLAGS=-g -std=c++17 -Wall

src = $(wildcard roomInfo/*.cpp) \
      $(wildcard playerInput/*.cpp) \
      $(wildcard global/*.cpp) \
      $(wildcard combatModule/*.cpp) \
      $(wildcard dialogueModule/*.cpp) \
      $(wildcard saveGame/*.cpp) \
      $(wildcard menuInterface/*.cpp) \
      $(wildcard *.cpp)
obj = $(src:.cpp=.o)

.PHONY: all
all: main

.PHONY: clean
clean:
	rm -f $(obj)

main: $(obj)
	$(CXX) -o $@ $^