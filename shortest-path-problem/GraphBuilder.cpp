#include "GraphBuilder.h"
#include <cctype>

void GraphBuilder::buildGraphFromFile(Graph& io_Graph, std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    
    std::string line;
    
    if (!i_InputFile) {
        throw std::invalid_argument("Error with input file!");
    }
    
    line = getLineNotEmpty(i_InputFile);
    o_Source = getIntFromLine(line);
    line = getLineNotEmpty(i_InputFile);
    o_Target = getIntFromLine(line);

	if (!io_Graph.IsValidVertex(o_Source) || !io_Graph.IsValidVertex(o_Target)) {
		throw std::invalid_argument("Invalid Source/Target vertex number in input file!");
	}

    while(!i_InputFile.eof()) {
        
        if (!i_InputFile.good()) {
            throw std::invalid_argument("Error with input file!");
        }
        
        std::getline(i_InputFile, line);
		if (isWhiteSpacesOnly(line)) {
            continue;
		}

		Edge currEdge = getEdgeFromLine(line);
		if (currEdge.m_Weight < 0) {
			throw std::invalid_argument("Invalid weight");
		}
        
		io_Graph.AddEdge(currEdge);
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
    std::string line = getLineNotEmpty(i_InputFile);
    int numOfVertices = getIntFromLine(line);
    
    Graph* newGraph = new AdjacencyList(numOfVertices);
    buildGraphFromFile(*newGraph, i_InputFile, o_Source, o_Target);
    
    return newGraph;
}

Graph* GraphBuilder::BuildAdjMatrixFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target) {
    std::string line = getLineNotEmpty(i_InputFile);
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
    
    throw std::invalid_argument("Error with input file structre!");
}

Edge GraphBuilder::getEdgeFromLine(const std::string& i_Str) {
    std::stringstream lineStream(i_Str);
	std::string myFloat;
	Edge inputEdge = { 0,0,0 };
    char dummy;
    
    if (lineStream >> inputEdge.m_Src >> inputEdge.m_Dest >> inputEdge.m_Weight) {
        if (!(lineStream >> dummy)) {
            return inputEdge;
        }
    }
    throw std::invalid_argument("Error with input file structre!");
}


std::string GraphBuilder::getLineNotEmpty(std::ifstream& i_InputFile) {
    std::string line = "";
    std::getline(i_InputFile, line);

    while(isWhiteSpacesOnly(line) && !i_InputFile.eof()) {
        std::getline(i_InputFile, line);
    }
    
    return line;
}
