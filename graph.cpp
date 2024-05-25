#include "graph.h"

//graph::graph()
//{
//    SetNumOfVertices();
//    SetNumOfEdges();
//    MakeEmptyGraph();
//    GetEdgesFromUser();
//
//    for (int i = 1; i <= n; i++) {
//        std::cout << "Adjacency list of vertex " << i << ": ";
//        for (int vertex: adjList[i-1]) {
//            std::cout << vertex+1 << " ";
//        }
//        std::cout << std::endl;
//    }
//}

void graph::SetNumOfVertices()
{
    std::cout << "Please enter number of vertices: ";
    std::cin >> this->n;
}

void graph::SetNumOfEdges()
{
    std::cout << "Please enter number of arches: ";
    std::cin >> this->m;
}

int graph::GetNumOfEdges() const
{
    return m;
}

int graph::GetNumOfVertices() const
{
    return n;
}

std::list<int> graph::GetEndList()
{
    return endList;
}

std::vector<std::list<int>> graph::GetAdjList() const
{
    return adjList;
}

void graph::MakeEmptyGraph()
{
    adjList.resize(n);
    color.resize(n);
    root.resize(n);
    endList.clear();

    for(int i=0 ; i < n ; i++)
    {
        adjList[i].clear();
    }
}

bool graph::IsAdjacent(int u,int v)
{
    if(std::find(adjList[u].begin(), adjList[u].end(),v) != adjList[u].end())
    {
        return true;
    }
    return false;
}

std::list<int> graph::GetAdjList(int u)
{
    return adjList[u];
}

void graph::AddEdge(int u,int v)
{
    CheckIfValidEdge(u,v);
    adjList[u-1].push_back(v-1);
}

void graph::RemoveEdge(int u,int v)
{
    adjList[u].remove(v);
}

void graph::CheckIfValidEdge(int u, int v)
{
    if(u > n || v > n || v == u || u <= 0 || v <= 0)
    {
        std::cout << "Invalid input";
        std::exit(1);
    }
}

void graph::GetEdgesFromUser()
{
    int u,v;
    std::cout << "Please enter pairs of numbers (the edges):" <<std::endl;
    for(int i=1 ; i<=m ; i++)
    {
        std::cin >> u >> v;
        AddEdge(u,v);
    }
}

std::vector<int> graph::GetRootList()
{
    return root;
}

void graph::BuildDirectedGraph()
{
    SetNumOfVertices();
    SetNumOfEdges();
    MakeEmptyGraph();
    GetEdgesFromUser();

//    for (int i = 1; i <= n; i++) {
//        std::cout << "Adjacency list of vertex " << i << ": ";
//        for (int vertex: adjList[i-1]) {
//            std::cout << vertex+1 << " ";
//        }
//        std::cout << std::endl;
//    }
}

void graph::visit(int u, int currRoot)
{
    root[u]=currRoot;
    color[u]='G';
    for (int vertex: adjList[u])
    {
        if(color[vertex] == 'W')
            visit(vertex, currRoot);
    }
    color[u]='B';
    endList.push_back(u);
}

void graph::DFS(std::list<int> vertexOrder)
{
    int currRoot;

    for(int v : vertexOrder)
        color[v]='W';

    for(int v : vertexOrder)
    {
        if(color[v] == 'W')
        {
            currRoot = v;
            visit(v, currRoot);
        }
    }
    for(int v: endList)
        std::cout << v+1 << " " <<std::endl;

    for(int v: root)
        std::cout << v+1 << " ";
}

