joust: Random.o main.o Knight.o
	g++ -Wall -pedantic -g -o joust Random.o main.o Knight.o

main.o: Random.h Knight.h weapon.cpp main.cpp
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

Knight.o: Random.h Knight.h Knight.cpp weapon.cpp
	g++ -Wall -pedantic -g -std=c++11 -c Knight.cpp

weapon.o: Random.h Random.cpp weapon.cpp
	g++ -Wall -pedantic -g -std=c++11 -c weapon.cpp

Random.o: Random.h Random.cpp
	g++ -Wall -pedantic -g -std=c++11 -c Random.cpp

clean:
	rm -f joust joust.exe Random.o main.o Knight.o weapon.o
