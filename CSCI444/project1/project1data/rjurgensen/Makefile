joust: main.o Random.o Weapon.o Knight.o
	g++ main.o Random.o Weapon.o Knight.o -o joust

main.o: main.cpp Knight.cpp Weapon.cpp Random.cpp
	g++ -c main.cpp

Knight.o: Knight.cpp Weapon.cpp
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp
	g++ -c Weapon.cpp

Random.o: Random.cpp
	g++ -c Random.cpp

clean:
	rm *.o
