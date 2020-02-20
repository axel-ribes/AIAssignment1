#pragma once

#include<vector>
#include "Node.h"
class Graph
{
private:
	std::vector<Node>* listOfNodes; 
	int heuristic(Node node, Node end);
	std::vector<Node> insertionSortPriority(std::vector<Node> vec, Node goal);
public:
	Graph();
	std::vector<Node>* getListOfNodes();
	void addNode(Node node);
	std::vector<Node> searchPathAstar(Node start, Node end);
};

