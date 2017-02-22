#cd ../..
#cd engine
#g++ -c *.cpp
#ar rvs engine.a *.o
#rm *.o
#cd ..
#cd testgames/genesis
g++ *.cpp ../../engine/engine.a -lSDL2 -std=c++11
