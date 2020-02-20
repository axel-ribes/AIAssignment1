#include "Graph.h"
#include "Node.h"
#include <map>
#include <iostream>

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
} //calculate the absolute distance to estimate the cost for A*

std::vector<Node> Graph::searchPathAstar(Node start, Node end) { //need to be filled out
	std::map<Node, Node>* previous = new std::map<Node, Node>();
	std::map<Node, int> totalCostValue; //starting with a cost of 0
	totalCostValue[start] = 0;
	
	previous->insert(std::pair<Node, Node>(start, start));

	std::vector<Node> front;
	front.push_back(start);

	while (!front.empty()) {
		Node current = front.at(0); //setting current node to the prior one
		front.erase(front.begin()); //this line is also a part of Simon's work
		if (current.getID() == end.getID()) {
			break; //if we are at the last node we stop here 
		}
		std::map<Node, int>::iterator next(current.getEdges()->begin());
		while (next != current.getEdges()->end()) {
			int actualCost = totalCostValue[current] + next->second;

			if (totalCostValue.find(next -> first) == totalCostValue.end() || actualCost < totalCostValue[next->first]) {
				totalCostValue.insert(std::pair<Node, int>(next->first, actualCost));
				front.push_back(next->first);
				if (previous->find(next->first) != previous->end()) {
					previous->at(next->first) = current;
				}
				else {
					previous->insert(std::pair<Node, Node>(next->first, current));
				}
			}
			//from this line to the end, Simon provided me the code because I couldn't figure out how to do this
			front = insertionSortPriority(front, end);
			++next;
		}
	}
	std::vector<Node> path;
	Node current = end;

	while (current.getID() != start.getID()) {
		path.push_back(current);
		current = previous->at(current);
	}
	path.push_back(start);
	std::reverse(path.begin(), path.end());
	return path;
}

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
} //this function has also been provided by Simon 
//its sorting the array of Nodes concerning the heuristic value between the current node and the end 

