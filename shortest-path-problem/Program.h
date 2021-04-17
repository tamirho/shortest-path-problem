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

class Program
{
private:
	Program() = default;
	static void RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, std::ostream& i_OutFile);
public:
	static void Run(const char* i_Inputfile, const char* i_Outputfile);
};

