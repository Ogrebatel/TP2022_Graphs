//
// Created by John on 14.12.2022.
//

#ifndef GRAPHS_MATRIX_GRAPH_H
#define GRAPHS_MATRIX_GRAPH_H

#include <iostream>
#include <cassert>
#include "IGraph.h"

class MatrixGraph: public IGraph {
 public:
    MatrixGraph(size_t size);
    MatrixGraph(const IGraph &graph);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    ~MatrixGraph() override;

private:
    std::vector<std::vector<bool>> _graph;
};



#endif //GRAPHS_MATRIX_GRAPH_H
