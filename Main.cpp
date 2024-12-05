#include "Edge.h"
#include "Graph.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }

    Graph* graph = new Graph(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object
    }

    graph->printMatrix();
    std::cout << std::endl << std::endl;
    graph->printOddVertices();
    std::cout << std::endl << std::endl;
    graph->printSP_ODD();
    std::cout << std::endl;

    delete graph;

    return 0;
}