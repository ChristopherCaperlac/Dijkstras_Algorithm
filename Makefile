all: clean build

build: Main.o Edge.o Vertex.o #Graph.o
	g++ -g -Wall Main.o Edge.o Vertex.o -o dijkstra

Edge.o: Edge.h Edge.cpp
	g++ -g -Wall -c Edge.cpp

Vertex.o: Vertex.h Vertex.cpp    
	g++ -g -Wall -c Vertex.cpp

#Graph.o: Graph.h Graph.cpp
#	g++ -g -Wall -c Graph.cpp

Main.o: Main.cpp #Graph.h
	g++ -g -Wall -c Main.cpp

clean:
	rm *.o dijkstra -f

run:
	./dijkstra < ./test_cases/all-odd.txt

.PHONY: demo
demo:
	./demo < ./test_cases/all-odd.txt

update:
	git pull origin main