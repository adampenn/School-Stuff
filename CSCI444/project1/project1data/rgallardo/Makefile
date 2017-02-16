Project4: main.o knight.o weapon.o Random.o 
	g++ main.o knight.o weapon.o Random.o  -o Project4

main.o: main.cpp
	g++ -c main.cpp

knight.o: knight.cpp knight.h 
	g++ -c knight.cpp

weapon.o: weapon.cpp weapon.h
	g++ -c weapon.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o Project4
