Joust_Game: Knight.o Random.o Weapon.o joust.o
	g++ joust.o Knight.o Weapon.o Random.o -o joust

joust.o: joust.cpp Knight.h Weapon.h
	g++ -c joust.cpp

Knight.o: Knight.cpp Knight.h Weapon.h Random.h
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean: 
	rm *.o
