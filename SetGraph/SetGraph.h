//
// Created by John on 14.12.2022.
//

#ifndef GRAPHS_SET_GRAPH_H
#define GRAPHS_SET_GRAPH_H

#include "IGraph.h"
#include "AVL.h"

class SetGraph: public IGraph {
 public:
    SetGraph(size_t size);
    SetGraph(const IGraph &graph);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    ~SetGraph() override;

private:
    std::vector<AVL<int>> _graph;
};


#endif //GRAPHS_SET_GRAPH_H
