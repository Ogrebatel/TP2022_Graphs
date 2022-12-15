//
// Created by ogrebatel on 15.12.22.
//

#include <gtest/gtest.h>

#include "Tests_ArcGraph.h"
#include "Tests_ListGraph.h"
#include "Tests_MatrixGraph.h"
#include "Tests_SetGraph.h"

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
