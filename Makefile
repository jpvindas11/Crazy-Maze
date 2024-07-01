all:
	g++ -Iinclude -Llib -o game src/*.cpp src/draw/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer