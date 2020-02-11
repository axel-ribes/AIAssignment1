#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

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

void createGraph(string file_name) {
	ifstream ifs(file_name);
	string line = "";
	while (getline(ifs, line))
	{
		//processing to create : nodes, edges --> typedef std::pair<int, int> edge;
		//graph is composed of vector<node> and vector<edge>
	}
	ifs.close();
}; //setting up a graph so we can process with astar

void findPath(/*graph*/) {
	//use astar to find path 
}

void main() {
	
	displayFile("test.txt");
}