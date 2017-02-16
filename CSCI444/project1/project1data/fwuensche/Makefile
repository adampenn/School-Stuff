Joust: main.o Knight.o Weapon.o Random.o
	g++ main.o Knight.o Weapon.o Random.o -o Joust
main.o: main.cpp Knight.h Weapon.h Random.h
	g++ -c main.cpp
Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp
Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp
Random.o: Random.cpp Random.h
	g++ -c Random.cpp
clean:
	rm *.o Joust
