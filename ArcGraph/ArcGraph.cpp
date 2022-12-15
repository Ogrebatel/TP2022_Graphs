//
// Created by John on 14.12.2022.
//

#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t size): _size(size) {}

ArcGraph::ArcGraph(const IGraph &graph): _size(graph.VerticesCount()) {
    for (int i = 0; i < _size; ++i) {
        auto nextVertices = graph.GetNextVertices(i);
        for (auto &vertex : nextVertices) {
            _graph.emplace_back(i, vertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < _size);
    assert(to >= 0 && to < _size);
    _graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return static_cast<int>(_size);
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _size);
    auto result = std::vector<int>();

    for (auto &iter : _graph){
        if(iter.from == vertex){
            result.push_back(iter.to);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _size);
    std::vector<int> result;

    for (auto &iter : _graph){
        if(iter.to == vertex){
            result.push_back(iter.from);
        }
    }

    return result;
}

ArcGraph::~ArcGraph() = default;
