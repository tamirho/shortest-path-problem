#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "GraphBuilder.h"
#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Heap.h"
#include "MinArray.h"

/*
 Class that contains the program's main functions.*/
class Program
{
private:
    Program() = default;
    // Get one of the algorithms and a graph, run and meassure the algorithm on the current grpah.
    static void RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, std::ostream& i_OutFile);
public:
    /*
     Function that runs that open the input files, builds 2 grpahs, and run the algorithms for each graph.
     Then write to output file the time that took to run each algorithm
     */
    static void Run(const char* i_Inputfile, const char* i_Outputfile);
};

