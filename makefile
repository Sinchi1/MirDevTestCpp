TARGET = main

CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
