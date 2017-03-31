cd ../..
cd engine
./build.sh
rm *.o
cd ..
cd testgames/snake
g++ main.cpp snake.cpp ../../engine/arch.a -lSDL2 -lSDL2_image -std=c++11
