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
        return -1;
    }

    Graph* graph = new Graph(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        graph->setEdge(startVertice - 1, endVertice - 1);
    }

    graph->printMatrix();
    std::cout << std::endl;
    graph->printOddVertices();
    std::cout << std::endl;
    graph->printSP_ODD();

    delete graph;

    return 0;
}