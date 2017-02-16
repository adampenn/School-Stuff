joust: main.o weapon.o Random.o knight.o
	g++ main.o weapon.o Random.o knight.o -o joust

weaopn.o: weapon.cpp weapon.h Random.o
	g++ -c weapon.cpp Random.o

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

testmain.o: main.cpp weapon.h
	g++ -c  main.cpp

knight.o: knight.cpp knight.h weapon.h
	g++ -c knight.cpp

clean:
	rm *.o
	rm joust
