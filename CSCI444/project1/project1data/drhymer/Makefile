ProjectJoust: main.o weapon.o knight.o
	g++ main.o weapon.o knight.o

knight.o: knight.cpp knight.h
	g++ -c knight.cpp

weapon.o: weapon.cpp weapon.h
	g++ -c weapon.cpp

main.o: main.cpp knight.h weapon.h
	g++ -c main.cpp

clean:
	rm *.o ProjectJoust
