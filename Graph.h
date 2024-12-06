#pragma once

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

    private:

        int** adjacencyMatrix;
        int numOfVertices;
        int numOfEdges;

        int getRelaxIndex(int**);
        void relaxVertex(int**, int);

    public:
    
        Graph(int, int);
        ~Graph();

        void setEdge(int, int); // edge is unweighted

        int getNumOfVertices();
        int getNumOfEdges();
        int* getAdjacentVertices(int); // return just the row of matrix
        int getDegree(int);

        void printMatrix();
        void printOddVertices();
        void printSP_ODD();
        void printSP(int);

};

#endif