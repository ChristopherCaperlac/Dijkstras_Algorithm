compile: clean build

all: clean build test

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

TEST_FILES = all-odd chords eco-florida small-network square-in-square triangle-in-triangle

test: run compare

run: dijkstra
	@for file in $(TEST_FILES); do \
		./dijkstra < ./test_cases/$${file}.txt > ./test_log/$${file}_actual.log 2>&1; \
	done

.PHONY: demo
demo:
	@for file in $(TEST_FILES); do \
		./demo < ./test_cases/$${file}.txt > ./test_log/$${file}_demo.log 2>&1; \
	done

compare:
	@for file in $(TEST_FILES); do \
		if [ ! -f ./test_log/$${file}_actual.log ]; then \
		echo "Missing $${file}_actual.log"; \
		continue; \
  	fi; \
		if [ ! -f ./test_log/$${file}_demo.log ]; then \
		echo "Missing $${file}_demo.log"; \
		continue; \
  	fi; \
		diff ./test_log/$${file}_actual.log ./test_log/$${file}_demo.log > ./test_diff/$${file}_diff.log || true; \
	done

update:
	git pull origin main