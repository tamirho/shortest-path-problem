#include <iostream>
#include <sstream>
#include "GraphBuilder.h"
#include "BellmanFord.h"

using namespace std;

int main(int argc, char* argv[]) {
    int src, target;
    
    try {
        
        Graph* graph = GraphBuilder::BuildAdjMatrixFromFile(argv[1], src, target);
        BellmanFord algo;
        ofstream outFile(argv[2], ios::app); // The name of the file
        
//        //for each function (3)
//        auto start = chrono::high_resolution_clock::now();
//        // unsync the I/O of C and C++.
//        ios_base::sync_with_stdio(false);
//        algo.Process(*graph, src);
//        auto end = chrono::high_resolution_clock::now();
//        // Calculating total time taken by the program.
//        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//        time_taken *= 1e-9;
//        outFile << graph.info() << algo.info() << fixed << time_taken << setprecision(9);
//        outFile << " sec" << endl;
//        outFile.close();
        
        
        cout <<  algo.Process(*graph, src) << endl;
        cout << algo.GetWeightOfShortestPathToTarget(target) << endl;
    }
    
    
    catch(std::exception& error) {
        cout << error.what() << endl;
    }

	return 0;
}
