# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
DEBUGFLAGS := -g
COVERAGEFLAGS := -fprofile-arcs -ftest-coverage

# All .cpp files in the directory
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

# Output executable
TARGET := chatapp

# Default build
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug build with -g
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)
	@echo "Built with debug symbols."

# Build with coverage flags
coverage: CXXFLAGS += $(COVERAGEFLAGS)
coverage: LDFLAGS += $(COVERAGEFLAGS)
coverage: clean $(TARGET)
	@echo "Built with coverage flags."

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with gdb
gdb: debug
	gdb ./$(TARGET)

# Run with valgrind
valgrind: debug
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TARGET)

# Generate coverage report (after running the program built with 'make coverage')
gcov-report:
	gcov $(SOURCES)

# Cleanup
clean:
	rm -f $(OBJECTS) $(TARGET) *.gcda *.gcno *.gcov
