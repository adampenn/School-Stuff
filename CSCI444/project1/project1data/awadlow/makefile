project04: Joust.o Random.o project04.o
	g++ Joust.o Random.o project04.o -o project04

Joust.o: Joust.cpp Joust.h Random.o
	g++ -c Joust.cpp Random.o

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

project04.o: project04.cpp Joust.o
	g++ -c project04.cpp Joust.o

clean:
	rm *.o 
	rm project04
