all: joust

joust:	main.o system.o knight.o weapon.o Random.o
	g++ main.o system.o knight.o weapon.o Random.o -o joust

main.o: main.cpp system.h
	g++ -c main.cpp -o main.o

system.o: system.cpp system.h knight.h
	g++ -c system.cpp -o system.o

knight.o: knight.cpp knight.h weapon.h
	g++ -c knight.cpp -o knight.o

weapon.o: weapon.cpp weapon.h Random.h
	g++ -c weapon.cpp -o weapon.o

Random.o: Random.cpp Random.h
	g++ -c Random.cpp -o Random.o

clean:
	rm *.o joust 
