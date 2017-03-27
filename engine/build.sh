sudo mkdir -p /usr/include/arch/
g++ -c *.cpp -std=c++11
ar rvs arch.a *.o
rm *.o
./genheader.sh
mv arch.a ..
sudo cp *.h /usr/include/arch/
