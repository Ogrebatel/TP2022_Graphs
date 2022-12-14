//
// Created by John on 14.12.2022.
//

#ifndef GRAPHS_ARC_GRAPH_H
#define GRAPHS_ARC_GRAPH_H

#include "IGraph.h"
#include "Vertice.h"

class ArcGraph: public IGraph {
 public:
    ArcGraph(size_t size);
    ArcGraph(const IGraph &graph);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    ~ArcGraph() override;

private:
    std::vector<Vertice> _graph;
};


#endif //GRAPHS_ARC_GRAPH_H
