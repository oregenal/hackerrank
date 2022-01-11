CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -pedantic -ggdb

SRCS=$(wildcard *.cpp)
BINS=$(patsubst %.cpp, %, $(SRCS))

.PHONY:default clean

default:$(BINS)

%:%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(BINS) input/ output/
