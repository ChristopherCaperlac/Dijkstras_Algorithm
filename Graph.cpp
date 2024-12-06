#include "Graph.h"
#include <iostream>

Graph::Graph(int numOfVertices, int numOfEdges) {

    this->adjacencyMatrix = new int* [numOfVertices];
    for (int i = 0; i < numOfVertices; i++) {
        this->adjacencyMatrix[i] = new int[numOfVertices];
    }
    this->numOfVertices = numOfVertices;
    this->numOfEdges = numOfEdges;

}

Graph::~Graph() {

    for (int i = 0; i < numOfVertices; i++) {
        delete[] this->adjacencyMatrix[i];
    }
    delete[] this->adjacencyMatrix;

}

void Graph::setEdge(int firstIndex, int secondIndex) {
    adjacencyMatrix[firstIndex][secondIndex] = 1;
    adjacencyMatrix[secondIndex][firstIndex] = 1;
}

int Graph::getNumOfVertices() {
    return numOfVertices;
}

int Graph::getNumOfEdges() {
    return numOfEdges;
}

int *Graph::getAdjacentVertices(int index) {
    return adjacencyMatrix[index];
}

int Graph::getDegree(int index) {

    int* adjacentVertices = adjacencyMatrix[index];
    int degree = 0;
    for (int i = 0; i < numOfVertices; i++) {
        if (adjacentVertices[i] == 1)
            degree++;
    }
    return degree;

}

// TODO: Implement this
void Graph::printMatrix() {
}

// TODO: Implement this
void Graph::printOddVertices() {
}

// TODO: Implement using printSP
void Graph::printSP_ODD() {
}

void Graph::printSP(int index) {

    std::cout << "Single source shortest path lengths from node " << index+1 << std::endl;

    // table[i] contains current shortest path length and isRelaxed
    int** table = new int*[numOfVertices];
    for (int i = 0; i < numOfVertices; i++) {
        table[i] = new int[2];
    }
    for (int i = 0; i < numOfVertices; i++) {
        table[i][0] = INT32_MAX;
        table[i][1] = 0;
    }
    table[index][0] = 0; // source node has shortest path length of zero

    int relaxIndex;
    for (int i = 0; i < numOfVertices; i++) {
        relaxIndex = getRelaxIndex(table);
        if (relaxIndex == -1) {
            std::cout << "Relaxation Error";
            return;
        }
        relaxVertex(table, relaxIndex);
    }

    for (int i = 0; i < numOfVertices; i++) {
        std::cout << "  " << i+1 << ": " << table[i][0] << std::endl;
    }

    for (int i = 0; i < numOfVertices; i++) {
        delete[] table[i];
    }
    delete[] table;

}

int Graph::getRelaxIndex(int** table) {

    int minimum = INT32_MAX;
    int index = -1;
    for (int i = 0; i < numOfVertices; i++) {
        if (table[i][1] == 1)
            continue;
        if (table[i][0] < minimum) {
            minimum = table[i][0];
            index = i;
        }
    }

    return index;

}

void Graph::relaxVertex(int** table, int index) {

    int lengthToIndexVertex = table[index][0];
    int newLength;
    for (int i = 0; i < numOfVertices; i++) {
        if (adjacencyMatrix[index][i] == 0)
            continue;
        else
        newLength = lengthToIndexVertex + 1;
        if (newLength < table[i][0])
            table[i][0] = newLength;
    }
    table[index][1] = 1;

}