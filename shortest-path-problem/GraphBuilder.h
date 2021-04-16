#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


class GraphBuilder {
public:
    static Graph* BuildAdjListFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target);
    static Graph* BuildAdjMatrixFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target);
private:
	GraphBuilder() = default;
    static void buildGraphFromFile(Graph& graph, std::ifstream& i_InputFile, int& o_Source, int& o_Target);
    static int getIntFromLine(const std::string& i_Str);
    static Edge getEdgeFromLine(const std::string& i_Str);
};
