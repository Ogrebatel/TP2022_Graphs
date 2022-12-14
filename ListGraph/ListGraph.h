//
// Created by John on 14.12.2022.
//

#ifndef GRAPHS_LIST_GRAPH_H
#define GRAPHS_LIST_GRAPH_H

#include <iostream>
#include "iostream"
#include "IGraph.h"
#include <cassert>

class ListGraph: public IGraph {
 public:
    ListGraph(size_t size);
    ListGraph(const IGraph &graph);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    ~ListGraph() override;

 private:
    std::vector<std::vector<int>> _graph;
};


#endif //GRAPHS_LIST_GRAPH_H
