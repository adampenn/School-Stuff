Test: Joust.o Knight.o Weapon.o Random.o 
	g++ Joust.o Knight.o Weapon.o Random.o -o Test

Joust.o: Joust.cpp Knight.h Weapon.h Random.h
	g++ -c Joust.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean: rm *.o Test
