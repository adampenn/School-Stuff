main: Random.o Weapon.o Knight.o main.o
	g++ Random.o Weapon.o Knight.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

Knight.o: Knight.cpp
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp
	g++ -c Weapon.cpp

Random.o: Random.cpp
	g++ -c Random.cpp

clean:
	rm *.o main
