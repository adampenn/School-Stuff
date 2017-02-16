project4: Random.o Weapon.o Knight.o project4.o
	g++ Random.o Weapon.o Knight.o project4.o -o project4

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp

Knight.o: Knight.cpp Knight.h Weapon.h
	g++ -c Knight.cpp

project4.o: project4.cpp Knight.h
	g++ -c project4.cpp

clean:
	rm *.o project4
