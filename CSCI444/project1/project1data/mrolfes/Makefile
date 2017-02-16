p4: Random.o weapon.o knight.o p4.o
	g++ Random.o weapon.o knight.o p4.o -o p4

p4.o: p4.cpp
	g++ -c p4.cpp

knight.o: knight.cpp
	g++ -c knight.cpp

weapon.o: weapon.cpp
	g++ -c weapon.cpp

Random.o: Random.cpp
	g++ -c Random.cpp

clean:
	rm *.o p4
