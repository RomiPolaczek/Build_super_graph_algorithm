#ifndef SUPERGRAPH_H
#define SUPERGRAPH_H
#include "transposedGraph.h"


class SuperGraph : public graph{
    std::list<std::list<int>> superGAdjList;
public:
    void Sarir_Kosaraju_algorithm(graph origin);
};


#endif SUPERGRAPH_H
