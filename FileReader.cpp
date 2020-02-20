#include "FileReader.h"
#include "Graph.h"
#include "Node.h"

FileReader::FileReader(std::string fileName) : fileName(fileName){}

Graph FileReader::readFile() {
	Graph graph = Graph(); //creating the graph to be filled out by data
	std::ifstream ifs(fileName);
	std::string thisline; //line by line in the concerned file
	int posx, posy, id, id2, weight;
	posx = posy = id = id2 = weight = 0;
	while (std::getline(ifs, thisline))
	{
		int matchingWordsCount = sscanf_s(thisline.c_str(), "%d[fontsize=\"8\",pos=\"%d,%d\"];",&id, &posx, &posy); //set id posx and posy to matching strings
		//and returns the number of strings scanned
		if (matchingWordsCount == 3) {
			Node node = Node(id, std::pair<int, int>(posx, posy)); // creating a node with data
			graph.addNode(node); //adding the node to the list in the graph
		}
		else { //if we dont match 3 items and the file s correctly built, we are scanning an edge
			matchingWordsCount = sscanf_s(thisline.c_str(), "%d--%d [fontsize=\"8\",label=\"%d\"];",&id, &id2, &weight);
			if (matchingWordsCount == 3) {
				Node node1 = graph.getListOfNodes()->at(id); //if we are at edges, all nodes should be created by now 
				Node node2 = graph.getListOfNodes()->at(id2);
				node1.addEdge(node2, weight);
				node2.addEdge(node1, weight); //adding edges to each node
			}
		}
	}
	return graph;
}
