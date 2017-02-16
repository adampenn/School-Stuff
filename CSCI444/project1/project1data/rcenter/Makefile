JoustProject: Random.o Weapon.o Knight.o Joust.o
	g++ Random.o Weapon.o Knight.o Joust.o -o JoustProject

Joust.o: Joust.cpp Weapon.h Knight.h Random.h
	g++ -c Joust.cpp

Knight.o: Knight.cpp Weapon.h Knight.h Random.h 
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h 
	g++ -c Random.cpp

clean:
	rm *.o JoustProject
