#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "GraphBuilder.h"
#include "BellmanFord.h"

using namespace std;

int main(int argc, char* argv[]) {
    int src, target;
    
    try {
        
        Graph* graph = GraphBuilder::BuildAdjMatrixFromFile(argv[1], src, target);
        BellmanFord algo;
        ofstream outFile(argv[2], ios::app);
        
        cout <<  algo.Process(*graph, src) << endl;
        cout << algo.GetWeightOfShortestPathToTarget(target) << endl;
    }
    
    
    catch(std::exception& error) {
        cout << error.what() << endl;
    }

	return 0;
}


void RunAndMeassureAlgorithm(const Graph& i_Graph, FordBaseAlgorithm& i_AlgorithmFunction, int i_Src, int i_Traget, const ostream& i_OutFile)
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
    cout <<i_AlgorithmFunction.GetAlgorithmName() << " ";
    cout << i_AlgorithmFunction.GetWeightOfShortestPathToTarget(i_Traget) << endl;
    
    // File output
//    i_OutFile << i_Graph.GetGraphType() << " ";
//    i_OutFile << i_AlgorithmFunction.GetAlgorithmName() << " "
//    i_OutFile << fixed << time_taken << setprecision(9);
    i_OutFile << " sec" << endl;
}
