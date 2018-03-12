CXX=g++
CXXFLAGS=-g -std=c++11 -Wall

src = $(wildcard roomInfo/*.cpp) \
      $(wildcard playerInput/*.cpp) \
      $(wildcard global/*.cpp) \
      $(wildcard combatModule/*.cpp) \
      $(wildcard dialogModule/*.cpp) \
      $(wildcard *.cpp)
obj = $(src:.cpp=.o)

.PHONY: all
all: main

.PHONY: clean
clean:
	rm -f $(obj) main

main: $(obj)
	$(CXX) -o $@ $^