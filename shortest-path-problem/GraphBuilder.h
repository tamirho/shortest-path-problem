#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


class GraphBuilder {
public:
    static Graph* BuildAdjListFromFile(const char* i_FilePath, int& o_Source, int& o_Target);
    static Graph* BuildAdjMatrixFromFile(const char* i_FilePath, int& o_Source, int& o_Target);
private:
    static void buildGraphFromFile(Graph& graph, const char* i_FilePath, int& o_Source, int& o_Target);
    static int getIntFromLine(const std::string& i_Str);
    static Edge getEdgeFromLine(const std::string& i_Str);
};
