#Arch Game Engine is a 2D game engine written in C++ using SDL2

#Under Heavy Development

Build game engine library with:
g++ -c *.cpp
ar rvs ArchGE.a *.o

Build sample game with:
g++ main.cpp ArchGE/ArchGE.a -lSDL2
