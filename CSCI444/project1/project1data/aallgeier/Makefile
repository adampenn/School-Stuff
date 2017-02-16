project04: project04.o Knight.o Weapon.o Random.o
	g++ project04.cpp Knight.cpp Weapon.cpp Random.cpp -o project04
project04.o:project04.cpp Knight.h Weapon.h
	g++ -c project04.cpp
Knight.o:Knight.cpp Knight.h Weapon.h Random.h
	g++ -c Knight.cpp
Weapon.o:Weapon.cpp Weapon.h
	g++ -c Weapon.cpp
Random.o:Random.cpp Random.h
	g++ -c Random.cpp
clean:
	rm *.o main
