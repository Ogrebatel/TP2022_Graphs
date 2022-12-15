//
// Created by ogrebatel on 15.12.22.
//

#ifndef GRAPHS_TESTS_SETGRAPH_H
#define GRAPHS_TESTS_SETGRAPH_H

#include <gtest/gtest.h>
#include "IGraph.h"
#include "SetGraph.h"

class SetGraphTests: public testing::Test{
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

    SetGraph graph = SetGraph(7);
};

TEST_F(SetGraphTests, VerticesCount){
    EXPECT_EQ(graph.VerticesCount(), 7);
}

TEST_F(SetGraphTests, GetNextVertices0){
    std::vector<int> check = {1, 5};
    auto result = graph.GetNextVertices(0);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetNextVertices1){
    std::vector<int> check = {2, 3, 5, 6};
    auto result = graph.GetNextVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetNextVertices3){
    std::vector<int> check = {2, 4, 6};
    auto result = graph.GetNextVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetNextVertices5){
    std::vector<int> check = {4, 6};
    auto result = graph.GetNextVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetNextVertices6){
    std::vector<int> check = {4};
    auto result = graph.GetNextVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices1){
    std::vector<int> check = {0};
    auto result = graph.GetPrevVertices(1);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices2){
    std::vector<int> check = {1, 3};
    auto result = graph.GetPrevVertices(2);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices3){
    std::vector<int> check = {1};
    auto result = graph.GetPrevVertices(3);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices4){
    std::vector<int> check = {3, 5, 6};
    auto result = graph.GetPrevVertices(4);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices5){
    std::vector<int> check = {0, 1};
    auto result = graph.GetPrevVertices(5);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

TEST_F(SetGraphTests, GetPrevVertices6){
    std::vector<int> check = {1, 3, 5};
    auto result = graph.GetPrevVertices(6);
    auto checkIter = check.begin();
    for (auto &resultIter: result) {
        EXPECT_EQ(*checkIter, resultIter);
        checkIter++;
    }
}

#endif //GRAPHS_TESTS_SETGRAPH_H
