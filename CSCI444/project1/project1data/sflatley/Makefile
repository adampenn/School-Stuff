Joustgame: main.o knight.o weapons.o Random.o
	g++ main.o knight.o weapons.o Random.o -o Joustgame

main.o: main.cpp knight.h weapons.h
	g++ -c main.cpp

knight.o: knight.cpp knight.h weapons.h Random.h
	g++ -c knight.cpp

weapons.o: weapons.cpp weapons.h
	g++ -c weapons.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o Joustgame

