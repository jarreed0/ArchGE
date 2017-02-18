cd ../..
cd engine
g++ -c *.cpp
ar rvs engine.a *.o
rm *.o
cd ..
cd testgames/park
g++ main.cpp park.cpp ../../engine/engine.a -lSDL2 -std=c++11
