#include <iostream>
#include "GraphBuilder.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    
    
//    std::ifstream inputFile;
//    inputFile.open(argv[1]);
//    std::string line;
//
//    if (!inputFile) {
//        throw std::invalid_argument("Error with inputFile!");
//    }
//
//    std::getline(inputFile, line);
//    cout << GraphBuilder::getIntFromLine(line) <<endl;
//    std::getline(inputFile, line);
//    cout << GraphBuilder::getIntFromLine(line) <<endl;
//    std::getline(inputFile, line);
//    cout << GraphBuilder::getIntFromLine(line) <<endl;
//
//    while(!inputFile.eof()) {
//
//        if (!inputFile.good()) {
//            throw std::invalid_argument("Error with inputFile!");
//        }
//
//        std::getline(inputFile, line);
//        Edge curr = GraphBuilder::getEdgeFromLine(line);
//        cout << curr.m_Src << "," << curr.m_Dest << "," << curr.m_Weight <<endl;
//    }
//
//
//    inputFile.close();
    
    int src, target;
    try {
        Graph* lst = GraphBuilder::BuildAdjListFromFile(argv[1], src, target);
        lst->PrintGraph();
    }
    catch(std::exception& error) {
        cout << error.what() << endl;
    }

    
    
	return 0;
}
