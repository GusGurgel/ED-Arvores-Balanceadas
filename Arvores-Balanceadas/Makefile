out: main.o person.o gdate.o avl.o
	g++ main.o person.o gdate.o avl.o -o out

main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

gdate.o: gdate.cpp gdate.h
	g++ -c gdate.cpp

avl.o: avl.cpp avl.h
	g++ -c avl.cpp

clean:
	rm main.o person.o gdate.o avl.o