#include "superGraph.h"

void SuperGraph::Sarir_Kosaraju_algorithm(graph origin)
{
    std::list<int> temp;
    temp.clear();
    for(int i=0 ; i < origin.GetNumOfVertices() ; i++)
    {
        temp.push_back(i);
    }
    origin.DFS(temp);
    endList = origin.GetEndList();
    std::reverse(endList.begin(), endList.end());
    transposedGraph gTransposed(origin);
    gTransposed.DFS(endList);

    std::vector<int> tempRoot = origin.GetRootList();
    //superGAdjList.(tempRoot[0]);
    for(int v:tempRoot)
    {

    }

    std::list<std::list<int>>::iterator firstListIt = superGAdjList.begin();

    if (firstListIt != superGAdjList.end()) {
        // Inserting the number at the beginning of the first list
       // firstListIt->push_front(tempRoot[O]);
    }

}