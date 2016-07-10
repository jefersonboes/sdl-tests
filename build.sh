rm screen.o Box.o

g++ -std=c++11 -c screen.cpp `sdl2-config --cflags --libs`

g++ -std=c++11 -c Box.cpp `sdl2-config --cflags --libs`

g++ -std=c++11 -o test SDLTest.cpp screen.o Box.o `sdl2-config --cflags --libs`

