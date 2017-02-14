################################################################
# This makefile is for the temp main file for testing purposes.
# Created by: Avery Reed on 2/14/17
# Last Edited by: Avery Reed 2/14/17
################################################################

FLAGS = -lSDL2

################################################################
# Build Game
################################################################
a.out: main.o arch.o
	g++ main.o arch.o $(FLAGS)

################################################################
# Build Engine
################################################################
#ArchGE main functions
arch.o: arch.cpp arch.h global.h
	g++ -c arch.cpp

#Global variables/function class
#global.o: global.cpp global.h
#	g++ -c global.cpp

################################################################
# Build temp main
################################################################
main.o: main.cpp arch.h
	g++ -c main.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
