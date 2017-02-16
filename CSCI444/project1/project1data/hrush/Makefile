Game:joust.o Random.o weapon.o knight.o
	g++ joust.o Random.o knight.o weapon.o -o Game

joust.o: joust.cpp knight.h weapon.h Random.h
	g++ -c joust.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

knight.o: knight.cpp knight.h Random.h
	g++ -c knight.cpp
	
weapon.o: weapon.cpp weapon.h Random.h
	g++ -c weapon.cpp
	
clean:
	rm *.o
