# Set compiler variables
CXX = g++

# Debug and Release build flags
CXXFLAGS_DEBUG = -std=c++20 -O0 -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wshadow -Werror
CXXFLAGS_RELEASE = -std=c++20 -O2 -DNDEBUG -pedantic-errors

# Assign Build Flags
CXXFLAGS = $(CXXFLAGS_DEBUG)

# Object files variable (add new files here, only if a .cpp)
OBJS = src/main.o src/utils/operations.o src/utils/io.o src/utils/conversions.o

.PHONY: all run clean

all: src/main.bin

# Main program target
main.bin: $(OBJS)
	@$(CXX) $(CXXFLAGS) -o src/main.bin $(OBJS)

# Generic rule for building C++ object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies (add new files here, only if a .cpp, ex:"io/io.o: io/io.h")
src/utils/operations.o: src/utils/operations.h
src/utils/io.o: src/utils/io.h
src/utils/conversions.o: src/utils/conversions.h

run: main.bin
	@./src/main.bin

clean:
	@rm -f src/*.o src/*.bin src/utils/*.o src/utils/*.bin