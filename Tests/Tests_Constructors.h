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
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromArcGraph, constructListGraph){
    ListGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromArcGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromArcGraph, constructSetGraph){
    SetGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
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
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromListGraph, constructListGraph){
    ListGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromListGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromListGraph, constructSetGraph){
    SetGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
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

    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromMatrixGraph, constructListGraph){
    ListGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromMatrixGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromMatrixGraph, constructSetGraph){
    SetGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
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
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromSetGraph, constructListGraph){
    ListGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromSetGraph, constructMatrixGraph){
    MatrixGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

TEST_F(FromSetGraph, constructSetGraph){
    SetGraph toCheck(graph);
    ASSERT_EQ(toCheck.VerticesCount(), graph.VerticesCount());

    std::vector<int> canonical;
    std::vector<int> check;

    mainBFS(graph, [& canonical](int vertex){ canonical.push_back(vertex); });
    mainBFS(toCheck, [& check](int vertex){ check.push_back(vertex); });

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }

    canonical = std::vector<int>();
    check = std::vector<int>();

    for (int i = 0; i < canonical.size(); ++i) {
        EXPECT_EQ(canonical[i], check[i]);
    }
}

#endif //GRAPHS_TESTS_CONSTRUCTORS_H
