project4: Random.o knight.o joust.o weapon.o
	g++ Random.o knight.o joust.o weapon.o -o project4

joust.o: joust.cpp knight.h
	g++ -c joust.cpp

weapon.o: weapon.cpp weapon.h Random.h
	g++ -c weapon.cpp

knight.o: knight.cpp knight.h weapon.h
	g++ -c knight.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o

