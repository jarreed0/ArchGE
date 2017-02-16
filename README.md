#Arch Game Engine is a 2D game engine written in C++ using SDL2

#Under Heavy Development

Note: the actual engine and library is in ArchGE/ and the sample code is in /

Install Manage (on Linux/OSX and possibly Windows if you have the Ubunut SHELL but not sure):

chmod u+x manage

./manage -i

./manage -s

Test Engine and Game with Manage (on Linux/OSX and possibly Windows if you have the Ubunut SHELL but not sure):

manage -t

Build game engine library with:

g++ -c *.cpp

ar rvs ArchGE.a *.o

Build sample game with:

g++ main.cpp ArchGE/ArchGE.a -lSDL2
