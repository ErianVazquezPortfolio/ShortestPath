all:Floyd-Warshall

Floyd-Warshall: main.o
	g++ main.o -o Floyd-Warshall
	
main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *o Floyd-Warshall