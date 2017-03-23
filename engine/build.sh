rm arch.h
g++ -c *.cpp -std=c++11
ar rvs arch.a *.o
rm *.o
./genheader.sh

