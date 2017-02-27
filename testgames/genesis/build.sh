cd ../..
cd engine
#g++ -c *.cpp
#ar rvs engine.a *.o
#rm *.o
./build.sh
cd ..
cd testgames/genesis
g++ *.cpp ../../engine/engine.a -lSDL2 -std=c++11
