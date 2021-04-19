#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

/*
 A class that handles graph building from a file.
 */
class GraphBuilder {
private:
    GraphBuilder() = default;
    
    /*
     A function that constructs a graph from a file according to the following format:
     3 Integers that represent the number of vertices, the source vertex and the target vertex.
     After that each line represent a new edge in the graph with the values - source, destination and weight.
     Input: Graph(ref) , File(ref) and two output parameters for source and target vertices.
     */
    static void buildGraphFromFile(Graph& graph, std::ifstream& i_InputFile, int& o_Source, int& o_Target);
    
    // A function for verifying and converting from a string to an integer.
    static int getIntFromLine(const std::string& i_Str);
    
    // A function for verifying and converting from a string to an Edge (src, dest, weight).
    static Edge getEdgeFromLine(const std::string& i_Str);
    
public:
    
    /*
     Input: File(ref) and two output parameters for source and target vertices.
     Output: A pointer to a new Adjacency List (Graph) that consists of the details in the file given
     */
    static Graph* BuildAdjListFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target);
    
    /*
     Input: File(ref) and two output parameters for source and target vertices.
     Output: A pointer to a new Adjacency Matrix (Graph) that consists of the details in the file given
     */
    static Graph* BuildAdjMatrixFromFile(std::ifstream& i_InputFile, int& o_Source, int& o_Target);
};
