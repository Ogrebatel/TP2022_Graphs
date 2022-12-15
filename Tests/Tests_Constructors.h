//
// Created by John on 15.12.2022.
//

#ifndef GRAPHS_TESTS_CONSTRUCTORS_H
#define GRAPHS_TESTS_CONSTRUCTORS_H

#include <gtest/gtest.h>
#include "IGraph.h"
#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

class FromArcGraph: public testing::Test{
protected:
    void SetUp() override {
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
    }

    ArcGraph graph = ArcGraph(7);
};

TEST_F(FromArcGraph, constructArcGraph){
    ArcGraph toCheck(graph);
    std::vector<int> check = {4, 6};

    auto result = toCheck.GetNextVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromArcGraph, constructListGraph){
    ListGraph toCheck(graph);
    std::vector<int> check = {4, 6};

    auto result = toCheck.GetNextVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromArcGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    std::vector<int> check = {4, 6};

    auto result = toCheck.GetNextVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromArcGraph, constructSetGraph){
    SetGraph toCheck(graph);
    std::vector<int> check = {4, 6};

    auto result = toCheck.GetNextVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

class FromListGraph: public testing::Test{
protected:
    void SetUp() override {
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
    }

    ListGraph graph = ListGraph(7);
};

TEST_F(FromListGraph, constructArcGraph){
    ArcGraph toCheck(graph);
    std::vector<int> check = {2, 4, 6};

    auto result = toCheck.GetNextVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromListGraph, constructListGraph){
    ListGraph toCheck(graph);
    std::vector<int> check = {2, 4, 6};

    auto result = toCheck.GetNextVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromListGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    std::vector<int> check = {2, 4, 6};

    auto result = toCheck.GetNextVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromListGraph, constructSetGraph){
    SetGraph toCheck(graph);
    std::vector<int> check = {2, 4, 6};

    auto result = toCheck.GetNextVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}


class FromMatrixGraph: public testing::Test{
protected:
    void SetUp() override {
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
    }

    MatrixGraph graph = MatrixGraph(7);
};

TEST_F(FromMatrixGraph, constructArcGraph){
    ArcGraph toCheck(graph);
    std::vector<int> check = {2, 3, 5, 6};

    auto result = toCheck.GetNextVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromMatrixGraph, constructListGraph){
    ListGraph toCheck(graph);
    std::vector<int> check = {2, 3, 5, 6};

    auto result = toCheck.GetNextVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromMatrixGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    std::vector<int> check = {2, 3, 5, 6};

    auto result = toCheck.GetNextVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromMatrixGraph, constructSetGraph){
    SetGraph toCheck(graph);
    std::vector<int> check = {2, 3, 5, 6};

    auto result = toCheck.GetNextVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}


class FromSetGraph: public testing::Test{
protected:
    void SetUp() override {
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
    }

    ArcGraph graph = SetGraph(7);
};

TEST_F(FromSetGraph, constructArcGraph){
    ArcGraph toCheck(graph);
    std::vector<int> check = {4};

    auto result = toCheck.GetNextVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromSetGraph, constructListGraph){
    ListGraph toCheck(graph);
    std::vector<int> check = {4};

    auto result = toCheck.GetNextVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromSetGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    std::vector<int> check = {4};

    auto result = toCheck.GetNextVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(FromSetGraph, constructSetGraph){
    SetGraph toCheck(graph);
    std::vector<int> check = {4};

    auto result = toCheck.GetNextVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

#endif //GRAPHS_TESTS_CONSTRUCTORS_H
