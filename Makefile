# Compiler settings
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17
LDFLAGS =

# Find all .cpp files in current directory
SOURCES = $(wildcard *.cpp)
TARGETS = $(SOURCES:.cpp=)

# Default target
all: $(TARGETS)

# Rule to build each executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# Clean build files
clean:
	rm -f $(TARGETS)

.PHONY: all clean