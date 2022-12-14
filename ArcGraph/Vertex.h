//
// Created by John on 14.12.2022.
//

#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H

struct Vertex {
    Vertex(int from, int to): from(from), to(to) {}
    int from;
    int to;
};

#endif //GRAPHS_VERTEX_H
