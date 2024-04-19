CFLAGS = -Wall -Wextra -pedantic-errors

out: main.o person.o gdate.o avl.o gtable.o
	g++ $(CFLAGS) main.o person.o gdate.o avl.o gtable.o -o out

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp

person.o: person.cpp person.h
	g++ -c $(CFLAGS) person.cpp

gdate.o: gdate.cpp gdate.h
	g++ -c $(CFLAGS) gdate.cpp

avl.o: avl.cpp avl.h node.h
	g++ -c $(CFLAGS) avl.cpp

gtable.o: gtable.cpp gtable.h
	g++ -c $(CFLAGS) gtable.cpp

run:
	@clear
	@echo
	@./out

clear:
	rm main.o person.o gdate.o avl.o gtable.o
