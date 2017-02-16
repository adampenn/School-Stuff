Joust: Knight.o Weapon.o main.o Random.o
	g++ Knight.o Weapon.o main.o Random.o -o Joust

Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

main.o: main.cpp Knight.h
	g++ -c main.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o Joust
