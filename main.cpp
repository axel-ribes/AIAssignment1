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
	int start,end;
	start = end = 0;
	
	cout << "Please enter the start node : " << endl;
	cin >> start;
	while (!cin || start > 64 || start < 0)
	{
		cout << "Please enter a valid Node Between 0 and 63 :" << endl;
		cin.clear();
		cin.ignore();
		cin >> start;
	}

	cout << endl << "Please enter the end node : " << endl;
	cin >> end;

	while (!cin || end > 64 || end < 0 || end == start)
	{
		cout << "Please enter a valid Node Between 0 and 63 and not the same as the start :" << endl;
		cin.clear();
		cin.ignore();
		cin >> end;
	}

	cout << endl << "Processing..." << endl << endl;

	std::vector<Node> path = graph.searchPathAstar(graph.getListOfNodes()->at(start), graph.getListOfNodes()->at(end));

	for (unsigned i = 0; i < path.size(); ++i)
		std::cout << "Node : " << path[i].getID() << std::endl;

	//cout << graph.getListOfNodes();
	//displayFile("random64_4_1485816605.dot");
}