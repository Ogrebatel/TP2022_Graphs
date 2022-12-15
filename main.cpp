//
// Created by John on 14.12.2022.
//

#include <iostream>

#include "IGraph.h"

#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

#include "GraphSort.h"
#include "GraphTraversal.h"

int main() {
    MatrixGraph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 5);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(3, 2);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 6);
    graph.AddEdge(5, 4);
    graph.AddEdge(5, 6);
    graph.AddEdge(6, 4);

    mainBFS(graph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(graph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;return 0;
}
