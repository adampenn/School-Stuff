Joust: joust.o Knight.o Weapon.o Random.o 
	g++ joust.o Knight.o Weapon.o Random.o -o joust

joust.o: joust.cpp
	g++ -c joust.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o joust
