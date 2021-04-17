#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "FordBaseAlgorithm.h"

class Program
{
private:
	Program() = default;
public:
	static void RunAndMeassureAlgorithm(FordBaseAlgorithm& i_AlgorithmFunction, const Graph& i_Graph, int i_Src, int i_Traget, std::ostream& i_OutFile);
};

