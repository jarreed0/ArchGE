cd engine
g++ -c *.cpp
ar rvs engine.a *.o
rm *.o
cd ..
g++ main.cpp snake.cpp engine/engine.a -lSDL2 -std=c++11
