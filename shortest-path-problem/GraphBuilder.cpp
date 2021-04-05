#include "GraphBuilder.h"

void GraphBuilder::BuildGraphFromFile(Graph* graph, const char* i_filePath, int& o_sourceVertex, int& o_destVertex) {
    
    std::ifstream inputFile;
    inputFile.open(i_filePath);
    
    if (!inputFile) {
        throw std::invalid_argument("Error with inputFile!");
    }
    
    int numOfVertexes;
    inputFile >> numOfVertexes >> o_sourceVertex >> o_destVertex;
    graph->MakeEmptyGraph(numOfVertexes);
    
    while (!inputFile.eof()) {
        int currentSrcVertex, currentDestVertex, currentWeight;
        if (!inputFile.good()) {
            throw std::runtime_error("Error Reading");
        }
        
        inputFile >> currentSrcVertex >> currentDestVertex >> currentWeight;
        graph->AddEdge(currentSrcVertex, currentDestVertex, currentWeight);
    }
    
    inputFile.close();
}

Graph* GraphBuilder::BuildAdjListFromFile(const char* i_filePath, int& o_sourceVertex, int& o_destVertex) {
    Graph* newGraph = new AdjacencyList();
    BuildGraphFromFile(newGraph, i_filePath, o_sourceVertex, o_destVertex);
    
    return newGraph;
}

Graph* GraphBuilder::BuildAdjMatrixFromFile(const char* i_filePath, int& o_sourceVertex, int& o_destVertex) {
    Graph* newGraph = new AdjacencyMatrix();
    BuildGraphFromFile(newGraph, i_filePath, o_sourceVertex, o_destVertex);
        
    return newGraph;
}
