test: testfile.o Random.o Knight.o Weapon.o testfile.o
	g++ Random.o Knight.o Weapon.o testfile.o -o test
Random.o: Random.cpp Random.h
	g++ -c Random.cpp
Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp 
Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp
testfile.o: testfile.cpp Random.h Weapon.h Knight.h
	g++ -c testfile.cpp 
make clean: 
	rm *.o test
