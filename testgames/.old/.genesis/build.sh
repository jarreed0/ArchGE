cd ../..
cd engine
#g++ -c *.cpp
#ar rvs engine.a *.o
#rm *.o
./build.sh
cd ..
cd testgames/genesis
g++ *.cpp ../../engine/arch.a -lSDL2 -std=c++11
