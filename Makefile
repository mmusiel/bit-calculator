# Set compiler variables
CXX = g++

# Debug and Release build flags
CXXFLAGS_DEBUG = -std=c++20 -O0 -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wshadow -Werror
CXXFLAGS_RELEASE = -std=c++20 -O2 -DNDEBUG -pedantic-errors

# Assign Build Flags
CXXFLAGS = $(CXXFLAGS_DEBUG)

# Object files variable (add new files here, only if a .cpp)
OBJS = src/main.o src/operations.o src/io.o src/conversions.o

.PHONY: all run clean

all: src/main.bin

# Main program target
main.bin: $(OBJS)
	@$(CXX) $(CXXFLAGS) -o src/main.bin $(OBJS)

# Generic rule for building C++ object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies (add new files here, only if a .cpp, ex:"io.o: io.h")
src/operations.o: src/operations.h
src/io.o: src/io.h
src/conversions.o: src/conversions.h

run: main.bin
	@./src/main.bin

clean:
	@rm -f src/*.o src/*.bin