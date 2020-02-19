#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "FileReader.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

void displayFile(string file_name) {
	ifstream ifs(file_name);
	string line = "";
	while (true)
	{
		getline(ifs, line);
		if (ifs.eof()) break;
		cout << line << endl;
	}
	ifs.close();
}; //reading file and display it


void main() {
	string fileName = "random64_4_1485816605.dot"; 
	FileReader* f = new FileReader(fileName); //creating the fileReader component
	Graph graph = f->readFile(); //parsing the file to create and fill the graph
	std::vector<Node> path = graph.searchPathAstar(graph.getListOfNodes()->at(0), graph.getListOfNodes()->at(60));

	for (unsigned i = 0; i < path.size(); ++i)
		std::cout << "Pass through: " << path[i].getID() << std::endl;

	//cout << graph.getListOfNodes();
	//displayFile("random64_4_1485816605.dot");
}