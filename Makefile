# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:src/%.cpp=build/%.o)

# Executable name
TARGET = ParkingLot_Simulator

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files into object files
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f build/*.o $(TARGET)

# Phony targets
.PHONY: all clean