#include "Graph.h"

Graph::Graph() {
	listOfNodes = new std::vector<Node>();
}

std::vector<Node>* Graph::getListOfNodes() {
	return listOfNodes;
} 

void Graph::addNode(Node node) {
	listOfNodes->push_back(node);
}

int Graph::heuristic(Node node, Node end) {
	return (std::abs(node.getCoordinates().first - end.getCoordinates().first) + std::abs(node.getCoordinates().second - end.getCoordinates().second));
} //calculate the distance

std::vector<Node> Graph::insertionSortPriority(std::vector<Node> vec, Node end) {
	if (vec.size() == 1 || vec.empty()) return vec;
	for (unsigned i = 1; i < vec.size(); ++i) {
		int toCompare = heuristic(vec[i], end);
		Node tmp = vec[i];
		int j = i;
		while (j > 0 && heuristic(vec[j - 1], end) > toCompare) {
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = tmp;
	}
	return vec;
}  //highly inspired by the work of Simon as i cannot figure out how to do this one

std::vector<Node> Graph::searchPathAstar(Node start, Node end) {
	//astar
}

//for the momment missing  insertionSortPriority and heuristicCalculation