#include "GraphBuilder.h"
#include <cctype>

void GraphBuilder::buildGraphFromFile(Graph& io_Graph, std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    
    std::string line;
    
    if (!i_InputFile) {
        throw std::invalid_argument("Error with inputFile!");
    }
    
    std::getline(i_InputFile, line);
    o_Source = getIntFromLine(line);
    std::getline(i_InputFile, line);
    o_Target = getIntFromLine(line);

	if (!io_Graph.IsValidVertex(o_Source) || !io_Graph.IsValidVertex(o_Target)) {
		throw std::invalid_argument("Invalid vertex number!");
	}

    while(!i_InputFile.eof()) {
        
        if (!i_InputFile.good()) {
            throw std::invalid_argument("Error with inputFile!");
        }
        
        std::getline(i_InputFile, line);
		if (isWhiteSpacesOnly(line)) {
			break;
		}

		Edge currEdge = getEdgeFromLine(line);
		if (currEdge.m_Weight < 0) {
			throw std::invalid_argument("Invalid weight");
		}
        
		io_Graph.AddEdge(currEdge);
    }

	while (!i_InputFile.eof()){
		if (!i_InputFile.good()) {
            throw std::invalid_argument("Error with inputFile!");
        }
		std::getline(i_InputFile, line);
		if (!isWhiteSpacesOnly(line)) {
			throw std::invalid_argument("Error with inputFile!");
		}
	}
}

bool GraphBuilder::isWhiteSpacesOnly(const std::string& i_Line) {
	for (const char& ch : i_Line) {
		if (!std::isspace(ch)) {
			return false;
		}
	}

	return true;
}

Graph* GraphBuilder::BuildAdjListFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    std::string line;
    std::getline(i_InputFile, line);
    int numOfVertices = getIntFromLine(line);
    
    Graph* newGraph = new AdjacencyList(numOfVertices);
    buildGraphFromFile(*newGraph, i_InputFile, o_Source, o_Target);
    
    return newGraph;
}

Graph* GraphBuilder::BuildAdjMatrixFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    std::string line;
    std::getline(i_InputFile, line);
    int numOfVertices = getIntFromLine(line);
    
    Graph* newGraph = new AdjacencyMatrix(numOfVertices);
    buildGraphFromFile(*newGraph, i_InputFile, o_Source, o_Target);
    
    return newGraph;
}

int GraphBuilder::getIntFromLine(const std::string& i_Str) {
    std::stringstream lineStream(i_Str);
	int res;
	char dummy;
    
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
    char dummy;
    
    if (lineStream >> inputEdge.m_Src >> inputEdge.m_Dest >> inputEdge.m_Weight) {
        if (!(lineStream >> dummy)) {
            return inputEdge;
        }
    }
    throw std::invalid_argument("Error with inputFile!");
}
