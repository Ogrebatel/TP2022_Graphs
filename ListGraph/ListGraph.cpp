//
// Created by John on 14.12.2022.
//

#include "ListGraph.h"

ListGraph::ListGraph(size_t size) {

}

ListGraph::ListGraph(const IGraph &graph): _graph(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        _graph[i] = graph.GetNextVertices(i);
    }
}


void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < _graph.size());
    assert(to >= 0 && to < _graph.size());
    _graph[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(_graph.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    return _graph[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    std::vector<int> prevVertices;

    for (int from = 0; from < _graph.size(); from++) {
        for (int to: _graph[from]) {
            if (to == vertex)
                prevVertices.push_back(from);
        }
    }

    return prevVertices;
}

ListGraph::~ListGraph() = default;
