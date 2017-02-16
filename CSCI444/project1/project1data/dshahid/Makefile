Joust: knight.o weapon.o Random.o main.o
	g++ knight.o weapon.o Random.o main.o -o Joust

knight.o: knight.cpp knight.h
	g++ -c knight.cpp

weapon.o: weapon.cpp weapon.h
	g++ -c weapon.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o Joust
