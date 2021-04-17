#include "main.h"

using namespace std;

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


	ofstream outputFile;
	try {
		outputFile.open(argv[2], ios::app);
        
		Heap heap;
		MinArray minArray;

		Dijkstra dijkstraHeapAlgorithm(heap);
		Dijkstra dijkstraArrayAlgorithm(minArray);
		BellmanFord bellmanFordAlgorithm;

		Program::RunAndMeassureAlgorithm(dijkstraHeapAlgorithm, *adjList, src, target, outputFile);
		Program::RunAndMeassureAlgorithm(dijkstraArrayAlgorithm, *adjList, src, target, outputFile);
		Program::RunAndMeassureAlgorithm(bellmanFordAlgorithm, *adjList, src, target, outputFile);

		Program::RunAndMeassureAlgorithm(dijkstraHeapAlgorithm, *adjMatrix, src, target, outputFile);
		Program::RunAndMeassureAlgorithm(dijkstraArrayAlgorithm, *adjMatrix, src, target, outputFile);
		Program::RunAndMeassureAlgorithm(bellmanFordAlgorithm, *adjMatrix, src, target, outputFile);

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

	return 0;
}
