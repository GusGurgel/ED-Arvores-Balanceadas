out: main.o gtable.o person.o gdate.o
	g++ main.o gtable.o person.o gdate.o -o out
main.o: main.cpp
	g++ -c main.cpp
gtable.o: gtable.cpp gtable.h
	g++ -c gtable.cpp
person.o: person.cpp person.h
	g++ -c person.cpp
gdate.o: gdate.h gdate.cpp
	g++ -c gdate.cpp
run: 
	@clear
	@echo
	@./out
