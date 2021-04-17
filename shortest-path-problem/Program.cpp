#include "Program.h"
using namespace std;

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
	i_OutFile << i_Graph.GetGraphType() << " ";
	i_OutFile << i_AlgorithmFunction.GetAlgorithmName() << " ";
	i_OutFile << fixed << time_taken << setprecision(9);
	i_OutFile << " sec" << endl;
}