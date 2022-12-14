cmake_minimum_required(VERSION 3.23)
project(SET_GRAPH CXX)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/SetGraph.h
        ${CMAKE_CURRENT_SOURCE_DIR}/AVL.h
        )

set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/SetGraph.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(
        ${PROJECT_NAME}
        ${IGRAPH_LIBRARIES}
)

target_include_directories(
        ${PROJECT_NAME} PUBLIC
        ${IGRAPH_INCLUDE_DIRS}
)

set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(${PROJECT_NAME}_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
