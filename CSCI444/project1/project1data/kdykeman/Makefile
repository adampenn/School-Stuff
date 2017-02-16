project4: Knight.o Weapon.o project4.o Random.o
	g++ project4.o Knight.o Weapon.o Random.o -o project4

project4.o: project4.cpp Knight.h Weapon.h
	g++ -c project4.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp
 
Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o project4
