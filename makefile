################################################################
# This makefile is for the temp main file for testing purposes.
# Created by: Avery Reed on 2/14/17
# Last Edited by: Avery Reed 2/14/17
################################################################

FLAGS = -lSDL2

################################################################
# Build Game
################################################################
a.out: main.o arch.o global.o object.o coord.o#engine.o
	g++ main.o arch.o global.o object.o coord.o $(FLAGS) #engine.o $(FLAGS)

################################################################
# Build Engine
################################################################
#Engine
#engine.o: arch.o global.o object.o coord.o
#	g++ -c arch.o global.o object.o coord.o $(FLAGS)

#ArchGE main functions
arch.o: arch.cpp arch.h global.h
	g++ -c arch.cpp

#Global variables/function class
global.o: global.cpp global.h
	g++ -c global.cpp

#Game objects
object.o: object.cpp object.h coord.h global.h
	g++ -c object.cpp

#Coordinate Point Storer
coord.o: coord.cpp coord.h global.h
	g++ -c coord.cpp

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
