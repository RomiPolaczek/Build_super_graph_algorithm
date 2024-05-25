#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>


class graph{
protected:
    int n;
    int m;
    std::vector<std::list<int>> adjList;
    std::vector<char> color;
    std::vector<int> root;
    std::list<int> endList;

    //ENUM
public:
    //graph();
    void SetNumOfVertices();
    void SetNumOfEdges();
    int GetNumOfVertices() const;
    int GetNumOfEdges() const;
    std::list<int> GetEndList();
    std::vector<int> GetRootList();
    std::vector<std::list<int>> GetAdjList() const;

    void CheckIfValidEdge(int u, int v);
    void BuildDirectedGraph();
    void GetEdgesFromUser();

    void visit(int u, int currRoot);
    void DFS(std::list<int> vertexOrder);


    void MakeEmptyGraph();
    bool IsAdjacent(int u,int v);
    std::list<int> GetAdjList(int u);
    void AddEdge(int u,int v);
    void RemoveEdge(int u,int v);
};

#endif GRAPH_H
