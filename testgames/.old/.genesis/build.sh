cd ../../..
cd "ArchGE(old_copies)"/ArchGE_10/engine
#g++ -c *.cpp
#ar rvs engine.a *.o
#rm *.o
./build.sh
cd ../../ArchGE/
cd testgames/genesis
g++ *.cpp ../../../"ArchGE(old_copies)"/ArchGE_10/engine/arch.a -lSDL2 -std=c++11
