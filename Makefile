
CXX=g++
CXXFLAG =-std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS= 

SRC_DIR=src
BUILD_DIR=build
BIN_DIR=bin
TARGET=$(BIN_DIR)/bird_maze


SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)


all: $(TARGET)


$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@


$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)


# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)


run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
