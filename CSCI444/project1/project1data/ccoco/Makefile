Joust: Random.o Weapon.o Knight.o main.o
	g++ Random.o Weapon.o Knight.o main.o -o Joust

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp

Knight.o: Knight.cpp Knight.h Weapon.h
	g++ -c Knight.cpp

main.o: main.cpp Knight.h
	g++ -c main.cpp

clean:
	rm *.o Joust