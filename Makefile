CXX = g++
CXXFLAGS = -Iinclude -ID:\\projects\\SFML\\include -LD:\\projects\\SFML\\lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,D:\\projects\\cpp-sfml/dlls
SRC_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/include/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

TARGET ?= main
TARGET_SRC = $(TARGET).cpp
TARGET_OBJ = $(TARGET).o
EXECUTABLE = $(TARGET).exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) $(TARGET_OBJ)
    $(CXX) -g -o $@ $^ $(CXXFLAGS)

$(TARGET_OBJ): $(TARGET_SRC)
    $(CXX) -g -c -o $@ $< $(CXXFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) -g -c -o $@ $< $(CXXFLAGS)

clean:
    rm -f $(EXECUTABLE) $(OBJ_FILES) $(TARGET_OBJ)

.PHONY: all clean
