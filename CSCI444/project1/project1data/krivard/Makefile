PLEASE: weap.o Random.o knig.o joost.o
	g++ weap.o Random.o knig.o joost.o -o The_Joost

weap.o: weap.cpp weap.h
	g++ -c weap.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

knig.o: knig.cpp knig.h
	g++ -c knig.cpp

joost.o: joost.cpp weap.h Random.h knig.h
	g++ -c joost.cpp

clean:
	rm *.o The_Joost
