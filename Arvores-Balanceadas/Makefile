out: main.o person.o gdate.o avl.o gtable.o
	g++ main.o person.o gdate.o avl.o gtable.o -o out

main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

gdate.o: gdate.cpp gdate.h
	g++ -c gdate.cpp

avl.o: avl.cpp avl.h node.h
	g++ -c avl.cpp
	
gtable.o: gtable.cpp gtable.h
	g++ -c gtable.cpp

run:
	@clear
	@echo
	@./out

clean:
	rm main.o person.o gdate.o avl.o gtable.o
