//
// Created by John on 14.12.2022.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t size): _graph(size) {
    for (auto &iter: _graph) {
        iter.resize(size, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph): MatrixGraph(graph.VerticesCount()) {
    for (int i = 0; i < _graph.size(); ++i) {
        auto nextVertices = graph.GetNextVertices(i);
        for (auto &vertex : nextVertices) {
            _graph[i][vertex] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < _graph.size());
    assert(to >= 0 && to < _graph.size());
    _graph[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(_graph.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    auto result = std::vector<int>();
    for (int j = 0; j < _graph.size(); ++j) {
        if (_graph[vertex][j] == true){
            result.push_back(j);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < _graph.size());
    auto result = std::vector<int>();
    for (int i = 0; i < _graph.size(); ++i) {
        if (_graph[i][vertex] == true){
            result.push_back(i);
        }
    }
    return result;
}

MatrixGraph::~MatrixGraph() = default;
