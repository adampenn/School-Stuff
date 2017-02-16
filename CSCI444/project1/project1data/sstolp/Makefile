Project4: Main.o Knight.o Random.o Weapon.o
	g++ Main.o Knight.o Random.o Weapon.o
Weapon.o: Weapon.cpp Weapon.h Random.h Knight.h
	g++ -c Weapon.cpp
Main.o: Weapon.h Random.h Knight.h Main.cpp
	g++ -c Main.cpp
Random.o: Random.h Random.cpp
	g++ -c Random.cpp
Knight.o: Knight.h Weapon.h Knight.cpp
	g++ -c Knight.cpp
clean:
	rm *.o Project4


