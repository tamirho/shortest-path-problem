#include <iostream>
#include <stdlib.h>
#include "Program.h"

/* This is a program to run and measure Bellman-Ford and Dijkstra's algorithms
 to find the weight of the lightest path from source to target vertex in a simple, non-negative weighted, directed grpah.
 The graph will be implemeted in 2 ways: adjacency list and adjacency matrix.
 The Dijkstra's algorithem will use a priority queue that will be implemented in 2 ways: with heap and with simple min array.
 
 The program gets the input from a text file, prints the result of each algorithem and each graph implemention
 and write the measures to the output file.
 
 Main paramters: argv[1] - The input file path
                 argv[2] - The ouput file path
 
 Input file parameters:
 3 Integers that represent the number of vertices, the source vertex and the target vertex.
 After that each line represent a new edge in the graph with the values - source, destination and weight.
 
 Example of input file, 5 vertexes, source vertex - 5, target vertex - 4 and 6 weigted edges:
 5
 5
 4
 5 1 10
 5 3 5
 1 2 1
 1 3 2
 2 4 2
 3 1 3

 To run all 3 algorithms, use Progrma::Run
 */
int main(int argc, char* argv[]) {

	try {
		if (argc < 3) {
			throw std::invalid_argument("Error with main program parameters");
		}
		Program::Run(argv[1], argv[2]);
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
		exit(1);
	}
	
	return 0;
}
