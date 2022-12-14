//
// Created by John on 14.12.2022.
//

#include "SetGraph.h"

SetGraph::SetGraph(size_t size): _graph(size) {}

SetGraph::SetGraph(const IGraph &graph): SetGraph(graph.VerticesCount()) {
    for (int i = 0; i < _graph.size(); ++i) {
        auto nextVertices = graph.GetNextVertices(i);
        for (auto vertex : nextVertices) {
            _graph[i].insert(vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < _graph.size());
    assert(to >= 0 && to < _graph.size());
    _graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(_graph.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    auto result = std::vector<int>();

    for (auto iter: _graph[vertex]) {
        result.push_back(iter);
    }

    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    std::vector<int> result;

    for (int from = 0; from < _graph.size(); from++) {
        for (auto to: _graph[from]) {
            if (to == vertex)
                result.push_back(from);
        }
    }

    return result;
}

SetGraph::~SetGraph() = default;
