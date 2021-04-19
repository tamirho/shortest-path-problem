#include "Program.h"

using namespace std;


void Program::Run(const char* i_Inputfile, const char* i_Outputfile) {
    
    int src, target;
    ifstream inputFile;
    Graph *adjMatrix = nullptr, *adjList = nullptr;
    
    try {
        inputFile.open(i_Inputfile);
        adjMatrix = GraphBuilder::BuildAdjMatrixFromFile(inputFile, src, target);
        inputFile.seekg(0, inputFile.beg);
        adjList = GraphBuilder::BuildAdjListFromFile(inputFile, src, target);
        inputFile.close();
    }
    catch (const std::exception& error) {
        if (adjMatrix) delete adjMatrix;
        if (adjList) delete adjList;
        if (inputFile) inputFile.close();
        throw;
    }
    
    
    ofstream outputFile;
    try {
        outputFile.open(i_Outputfile);
        
        Heap heap;
        MinArray minArray;
        
        Dijkstra dijkstraHeapAlgorithm(heap);
        Dijkstra dijkstraArrayAlgorithm(minArray);
        BellmanFord bellmanFordAlgorithm;
        
        RunAndMeassureAlgorithm(dijkstraHeapAlgorithm, *adjList, src, target, outputFile);
        RunAndMeassureAlgorithm(dijkstraArrayAlgorithm, *adjList, src, target, outputFile);
        RunAndMeassureAlgorithm(bellmanFordAlgorithm, *adjList, src, target, outputFile);
        
        RunAndMeassureAlgorithm(dijkstraHeapAlgorithm, *adjMatrix, src, target, outputFile);
        RunAndMeassureAlgorithm(dijkstraArrayAlgorithm, *adjMatrix, src, target, outputFile);
        RunAndMeassureAlgorithm(bellmanFordAlgorithm, *adjMatrix, src, target, outputFile);
        
        outputFile.close();
        delete adjMatrix;
        delete adjList;
    }
    catch (const std::exception& error) {
        if (adjMatrix) delete adjMatrix;
        if (adjList) delete adjList;
        if (outputFile) outputFile.close();
        throw;
    }
    
}


void Program::RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, ostream& i_OutFile)
{
    auto start = chrono::high_resolution_clock::now();
    
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    
    i_AlgorithmFunction.Process(i_Graph, i_Src);
    
    auto end = chrono::high_resolution_clock::now();
    
    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    // Screen output
    cout << i_Graph.GetGraphType() << " ";
    cout << i_AlgorithmFunction.GetAlgorithmName() << " ";
    cout << i_AlgorithmFunction.GetWeightOfShortestPathToTarget(i_Traget) << endl;
    
    if (!i_OutFile) {
        throw std::invalid_argument("Error with output file!");
    }
    
    // File output
    i_OutFile << "Time taken by function ";
    i_OutFile << i_Graph.GetGraphType() << " ";
    i_OutFile << i_AlgorithmFunction.GetAlgorithmName() << " is : ";
    i_OutFile << fixed << time_taken << setprecision(9);
    i_OutFile << " sec" << endl;
}
