cmake_minimum_required(VERSION 3.23)
project(GRAPHS)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(IGraph)

add_subdirectory(ArcGraph)
add_subdirectory(ListGraph)
add_subdirectory(MatrixGraph)
add_subdirectory(SetGraph)

add_subdirectory(Internals)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
        ${PROJECT_NAME}

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
