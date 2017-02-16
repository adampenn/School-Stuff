project4: joust.o Random.o weapon.o knight.o
	g++ joust.o Random.o weapon.o knight.o -o project4

joust.0: joust.cpp knight.h Random.h weapon.h
	g++ -c joust.cpp

knight.o: knight.cpp knight.h weapon.h
	g++ -c knight.cpp

weapon.o: weapon.cpp Random.h weapon.h
	g++ -c weapon.cpp

Random.o: Random.cpp
	g++ -c Random.cpp

     
     
