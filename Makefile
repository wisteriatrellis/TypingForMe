main: main.cpp
	g++ -std=c++17 -Wall --pedantic-errors -o main.exe main.cpp game.cpp model.cpp result.cpp scene.cpp -lncurses
