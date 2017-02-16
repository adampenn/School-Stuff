main: Knight.o Weapon.o Random.o main.o
	g++ Knight.o Weapon.o Random.o main.o -o Joust
main.o: main.cpp Knight.h Weapon.h Random.h
	g++ -c main.cpp
Knight.o: Knight.cpp Knight.h main.o
	g++ Knight.cpp
Weapon.o: Weapon.cpp Weapon.h
	g++ Weapon.cpp
Random.o: Random.cpp Random.h
	g++ Random.cpp
clean:
	rm *.o Joust
