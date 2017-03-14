cd ../..
cd engine
./build.sh
rm *.o
cd ..
cd testgames/snake
g++ main.cpp snake.cpp ../../engine/engine.a -lSDL2 -std=c++11
