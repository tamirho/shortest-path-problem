#include "GraphBuilder.h"
#include <string>
#include <sstream>

void GraphBuilder::buildGraphFromFile(Graph& graph, const char* i_FilePath, int& o_Source, int& o_Target) {
    
    std::ifstream inputFile;
    inputFile.open(i_FilePath);
    std::string line;

    if (!inputFile) {
        throw std::invalid_argument("Error with inputFile!");
    }
    
    std::getline(inputFile, line);
    int numOfVertices = getIntFromLine(line);
    std::getline(inputFile, line);
    o_Source = getIntFromLine(line);
    std::getline(inputFile, line);
    o_Target = getIntFromLine(line);
    
    graph.MakeEmptyGraph(numOfVertices);
    
    while(!inputFile.eof()) {
        
        if (!inputFile.good()) {
            throw std::invalid_argument("Error with inputFile!");
        }
        
        std::getline(inputFile, line);
        Edge currEdge = getEdgeFromLine(line);
        graph.AddEdge(currEdge);
    }
    
    inputFile.close();
}

Graph* GraphBuilder::BuildAdjListFromFile(const char* i_FilePath, int& o_Source, int& o_Target) {
    Graph* newGraph = new AdjacencyList();
    buildGraphFromFile(*newGraph, i_FilePath, o_Source, o_Target);
    
    return newGraph;
}

Graph* GraphBuilder::BuildAdjMatrixFromFile(const char* i_FilePath, int& o_Source, int& o_Target) {
    Graph* newGraph = new AdjacencyMatrix();
    buildGraphFromFile(*newGraph, i_FilePath, o_Source, o_Target);
        
    return newGraph;
}

int GraphBuilder::getIntFromLine(const std::string& i_Str) {
    std::stringstream lineStream(i_Str);
    int res, dummy;
    
    if (lineStream >> res) {
        
        if (!(lineStream >> dummy)) {
            return res;
        }
    }
    
    throw std::invalid_argument("Error with inputFile!");
}

Edge GraphBuilder::getEdgeFromLine(const std::string& i_Str) {
    std::stringstream lineStream(i_Str);
    Edge inputEdge;
    int dummy;

    if (lineStream >> inputEdge.m_Src >> inputEdge.m_Dest >> inputEdge.m_Weight) {
        if (!(lineStream >> dummy)) {
            return inputEdge;
        }
    }
    throw std::invalid_argument("Error with inputFile!");
}
