#include "transposedGraph.h"

transposedGraph::transposedGraph(const graph& g)
{
    n=g.GetNumOfVertices();
    m=g.GetNumOfEdges();
    MakeEmptyGraph();
    std::vector<std::list<int>> adjListOriginGraph = g.GetAdjList();
    for(int i=0 ; i<n ; i++)
        for(int vertex: adjListOriginGraph[i])
            AddEdge(vertex+1, i+1);

//    for (int i = 1; i <= n; i++) {
//        std::cout << "Adjacency list of vertex " << i << ": ";
//        for (int vertex: adjList[i-1]) {
//            std::cout << vertex+1 << " ";
//        }
//        std::cout << std::endl;
//    }
}

