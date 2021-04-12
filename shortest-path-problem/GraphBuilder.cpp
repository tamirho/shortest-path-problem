#include "GraphBuilder.h"


void GraphBuilder::buildGraphFromFile(Graph& graph, std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    
    std::string line;

    if (!i_InputFile) {
        throw std::invalid_argument("Error with inputFile!");
    }
    
    std::getline(i_InputFile, line);
    int numOfVertices = getIntFromLine(line);
    std::getline(i_InputFile, line);
    o_Source = getIntFromLine(line);
    std::getline(i_InputFile, line);
    o_Target = getIntFromLine(line);
    
    graph.MakeEmptyGraph(numOfVertices);
    
    while(!i_InputFile.eof()) {
        
        if (!i_InputFile.good()) {
            throw std::invalid_argument("Error with inputFile!");
        }
        
        std::getline(i_InputFile, line);
        Edge currEdge = getEdgeFromLine(line);
        if (currEdge.m_Weight < 0) {
            throw std::invalid_argument("Invalid weight");
        }
        
        graph.AddEdge(currEdge);
    }

}

Graph* GraphBuilder::BuildAdjListFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    Graph* newGraph = new AdjacencyList();
    buildGraphFromFile(*newGraph, i_InputFile, o_Source, o_Target);
    
    return newGraph;
}

Graph* GraphBuilder::BuildAdjMatrixFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    Graph* newGraph = new AdjacencyMatrix();
    buildGraphFromFile(*newGraph, i_InputFile, o_Source, o_Target);
        
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
