CC=emcc
LVL="-O0"

maze: mazeMain.o Space.o Empty.o Character.o Start.o Dinosaur.o Key.o Cheese.o Door.o Finish.o
	$(CC) -std=c++11 mazeMain.o Space.o Empty.o Character.o Start.o Dinosaur.o Key.o Cheese.o Door.o Finish.o -s WASM=1 --shell-file html_template/wasm_game_template.html $(LVL) -o ./build/wasm_maze.html

mazeMain.o: mazeMain.cpp
	$(CC) -std=c++11 -c mazeMain.cpp

Character.o: Character.hpp Character.cpp
	$(CC) -std=c++11 -c Character.cpp

Space.o: Space.cpp Space.hpp
	$(CC) -std=c++11 -c Space.cpp

Start.o: Start.cpp Start.hpp
	$(CC) -std=c++11 -c Start.cpp

Empty.o: Empty.cpp Empty.hpp
	$(CC) -std=c++11 -c Empty.cpp

Dinosaur.o: Dinosaur.cpp Dinosaur.hpp
	$(CC) -std=c++11 -c Dinosaur.cpp
	
Key.o: Key.cpp Key.hpp
	$(CC) -std=c++11 -c Key.cpp

Cheese.o: Cheese.cpp Cheese.hpp
	$(CC) -std=c++11 -c Cheese.cpp

Door.o: Door.cpp Door.hpp
	$(CC) -std=c++11 -c Door.cpp

Finish.o: Finish.cpp Finish.hpp
	$(CC) -std=c++11 -c Finish.cpp

clean:
	rm *.o wasm_maze.html wasm_maze.js wasm_maze.wasm
