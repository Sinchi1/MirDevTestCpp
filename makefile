TARGET = main
LIB = tests/libcfraction.so

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -fPIC

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET) $(LIB)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(LIB): Cfraction.cpp
	$(CXX) $(CXXFLAGS) -shared -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ) $(LIB)
