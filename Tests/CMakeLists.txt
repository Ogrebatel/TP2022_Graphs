cmake_minimum_required(VERSION 3.23)
project(GRAPH_TESTS)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

set(HEADERS
        Tests_ArcGraph.h
        Tests_ListGraph.h
        Tests_MatrixGraph.h
        Tests_SetGraph.h
        Tests_Constructors.h
        )

set(SOURCES
        tests.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(
        ${PROJECT_NAME}

        GTest::gtest_main

        ${IGRAPH_LIBRARIES}

        ${ARC_GRAPH_LIBRARIES}
        ${LIST_GRAPH_LIBRARIES}
        ${MATRIX_GRAPH_LIBRARIES}
        ${SET_GRAPH_LIBRARIES}

        ${GRAPH_INTERNALS_LIBRARIES}
)

target_include_directories(
        ${PROJECT_NAME} PUBLIC

        ${IGRAPH_INCLUDE_DIRS}

        ${ARC_GRAPH_INCLUDE_DIRS}
        ${LIST_GRAPH_INCLUDE_DIRS}
        ${MATRIX_GRAPH_INCLUDE_DIRS}
        ${SET_GRAPH_INCLUDE_DIRS}
        ${GRAPH_INTERNALS_INCLUDE_DIRS}
)

enable_testing()

