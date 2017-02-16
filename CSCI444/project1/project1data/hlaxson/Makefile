joust: Knight.o Weapon.o Random.o Main.o
	g++ Knight.o Weapon.o Random.o Main.o -o joust

Knight.o: Knight.cpp Knight.h Weapon.h
	g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h Random.h
	g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

Main.o: Main.cpp Knight.h
	g++ -c Main.cpp

clean:
	rm *.o joust
