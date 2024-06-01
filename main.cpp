#include "graph.h"
#include "transposedGraph.h"
#include "superGraph.h"

int main() {
    Graph g;
    g.BuildDirectedGraph();
    TransposedGraph gTransposed(g);
    SuperGraph superG;
    superG.Sarir_Kosaraju_Algorithm(g);
    superG.PrintSuperGraph();
}
