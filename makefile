###############################################################################
#  Author:       Adam Wright
#  Description:  Makefile for maze game which is compiled from c++ to
#				 Web Assembly using emscripten
###############################################################################

# Settings
CXX = emcc
OPTIMIZATION = -O3
CXXFLAGS = $(OPTIMIZATION) -std=c++11
WASM_FLAGS = -s WASM=1
HTML_TEMPLATE = --shell-file html_template/wasm_game_template.html

# Directories
DIRS = -I $(IDIR) -I $(SRCDIR) -I $(ODIR)
BUILD = build
SRCDIR = src
IDIR = include
ODIR = src/obj
HTML_TARGET = build/index.html
TARGETS = $(HTML_TARGET) build/wasm_maze.js build/wasm_maze.wasm

# Header Files
_DEPS = Character.hpp Space.hpp Start.hpp Empty.hpp Dinosaur.hpp Key.hpp Cheese.hpp Door.hpp Finish.hpp
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

# Object Files
_OBJ = Maze_Main.o Space.o Empty.o Character.o Start.o Dinosaur.o Key.o Cheese.o Door.o Finish.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))


###############################################################################

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(WASM_FLAGS) $(OBJ) $(HTML_TEMPLATE) -o $(HTML_TARGET)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(DIRS)

clean:
	rm $(ODIR)/*.o $(TARGETS)
