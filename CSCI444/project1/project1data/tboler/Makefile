Jousting: Knights.o Randoms.o Weapons.o Mains.o
	g++ Knights.o Randoms.o Weapons.o main.o -o Jousting

Knights.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Randoms.o: Random.cpp Random.h
	g++ -c Random.cpp

Weapons.o: Weapons.cpp Weapons.h
	g++ -c Weapons.cpp

Mains.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o Jousting


