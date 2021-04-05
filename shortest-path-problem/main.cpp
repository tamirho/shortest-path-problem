#include <iostream>
#include "GraphBuilder.h"

using namespace std;

int main(int argc, char* argv[]) {
    int src, dest;
    try {
        Graph* lst = GraphBuilder::BuildAdjListFromFile(argv[1], src, dest);
        lst->PrintGraph();
    }
    catch(std::exception& error) {
        cout << error.what() << endl;
    }
    
    
    
	return 0;
}
