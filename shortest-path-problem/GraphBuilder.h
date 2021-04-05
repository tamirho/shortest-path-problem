#pragma once
#include <fstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


class GraphBuilder {
public:
    static Graph* BuildAdjListFromFile(const char* i_filePath, int& o_sourceVertex, int& o_destVertex);
    static Graph* BuildAdjMatrixFromFile(const char* i_filePath, int& o_sourceVertex, int& o_destVertex);
private:
    static void BuildGraphFromFile(Graph* graph, const char* i_filePath, int& o_sourceVertex, int& o_destVertex);
};
