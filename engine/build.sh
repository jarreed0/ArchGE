sudo mkdir -p /usr/include/arch/
g++ -c *.cpp -std=c++11
ar rvs arch.a *.o
rm *.o
./genheader.sh
sudo cp arch.a /usr/lib/libarch.a
sudo cp *.h /usr/include/arch/
rm arch.a
rm arch.h
