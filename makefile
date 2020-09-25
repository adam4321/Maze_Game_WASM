###############################################################################
#  Author:       Adam Wright
#  Description:  Makefile for maze game which is compiled from c++ to
#				 Web Assembly using emscripten
###############################################################################

CXX = emcc
OPTIMIZATION = -O3
CXXFLAGS = $(OPTIMIZATION) -std=c++11 -Wall -Wextra
WASM_FLAGS = -s WASM=1
HTML_TEMPLATE = --shell-file html_template/wasm_game_template.html

HTML_TARGET = ./build/wasm_maze.html
TARGETS = $(HTML_TARGET) build/wasm_maze.js build/wasm_maze.wasm
SRC = src
INCLUDE = include
O_DIR = src/obj

maze: Maze_Main.o Space.o Empty.o Character.o Start.o Dinosaur.o Key.o Cheese.o Door.o Finish.o
	$(CXX) $(CXXFLAGS) $(WASM_FLAGS) Maze_Main.o Space.o Empty.o Character.o Start.o Dinosaur.o \
	Key.o Cheese.o Door.o Finish.o $(HTML_TEMPLATE) -o $(HTML_TARGET)

Maze_Main.o: Maze_Main.cpp
	$(CXX) $(CXXFLAGS) -c Maze_Main.cpp

Character.o: Character.hpp Character.cpp
	$(CXX) $(CXXFLAGS) -c Character.cpp

Space.o: Space.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp

Start.o: Start.cpp Start.hpp
	$(CXX) $(CXXFLAGS) -c Start.cpp

Empty.o: Empty.cpp Empty.hpp
	$(CXX) $(CXXFLAGS) -c Empty.cpp

Dinosaur.o: Dinosaur.cpp Dinosaur.hpp
	$(CXX) $(CXXFLAGS) -c Dinosaur.cpp
	
Key.o: Key.cpp Key.hpp
	$(CXX) $(CXXFLAGS) -c Key.cpp

Cheese.o: Cheese.cpp Cheese.hpp
	$(CXX) $(CXXFLAGS) -c Cheese.cpp

Door.o: Door.cpp Door.hpp
	$(CXX) $(CXXFLAGS) -c Door.cpp

Finish.o: Finish.cpp Finish.hpp
	$(CXX) $(CXXFLAGS) -c Finish.cpp

clean:
	rm *.o $(TARGETS)
