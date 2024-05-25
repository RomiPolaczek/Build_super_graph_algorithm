#include "graph.h"
#include "transposedGraph.h"
#include "superGraph.h"

int main() {
    graph g;
    g.BuildDirectedGraph();
    transposedGraph gTransposed(g);
    SuperGraph superG;
    superG.Sarir_Kosaraju_algorithm(g);
}
