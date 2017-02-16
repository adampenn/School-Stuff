project4: Knight.o Weapon.o Random.o main.o
	g++ Knight.o Weapon.o Random.o main.o -o project4
main.o: main.cpp Weapon.h Knight.h Random.h
	g++ -c main.cpp
Knight.o: Knight.cpp Weapon.h Knight.h
	g++ -c Knight.cpp
Weapon.o: Weapon.h Random.h Knight.h Weapon.cpp
	g++ -c Weapon.cpp
Random.o: Random.cpp Random.h
	g++ -c Random.cpp
clean:
	rm *.o project4
