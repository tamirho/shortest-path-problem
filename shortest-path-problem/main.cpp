#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "GraphBuilder.h"
#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Heap.h"
#include "MinArray.h"

using namespace std;

void RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, ostream& i_OutFile);

int main(int argc, char* argv[]) {
    
	int src, target;
	ifstream inputFile;
	Graph *adjMatrix = nullptr, *adjList = nullptr;

	try {
		inputFile.open(argv[1]);
		adjMatrix = GraphBuilder::BuildAdjMatrixFromFile(inputFile, src, target);
		inputFile.seekg(0, inputFile.beg);
		adjList = GraphBuilder::BuildAdjListFromFile(inputFile, src, target);
		inputFile.close();
	}
	catch (std::exception& error) {
		if (adjMatrix) delete adjMatrix;
		if (adjList) delete adjList;
		if (inputFile) inputFile.close();
		cout << error.what() << endl;
		exit(1);
	}
	catch (...) {
		cout << "Something went wrong" << endl;
		exit(1);
	}

	ofstream outputFile;
	try {
		outputFile.open(argv[2], ios::app);
        
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
    catch(std::exception& error) {
		if (adjMatrix) delete adjMatrix;
		if (adjList) delete adjList;
		if (outputFile) outputFile.close();
		cout << error.what() << endl;
		exit(1);
    }
	catch (...) {
		cout << "Something went wrong" << endl;
		exit(1);
	}

	return 0;
}


void RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, ostream& i_OutFile)
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
	i_OutFile << i_Graph.GetGraphType() << " ";
	i_OutFile << i_AlgorithmFunction.GetAlgorithmName() << " ";
	i_OutFile << fixed << time_taken << setprecision(9);
	i_OutFile << " sec" << endl;
}
