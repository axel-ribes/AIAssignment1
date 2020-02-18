#pragma once

#include<vector>
#include "Node.h"
class Graph
{
private:
	std::vector<Node>* listOfNodes; 

public:
	Graph();
	std::vector<Node> searchPathAstar(Node start, Node end);
	std::vector<Node>* getListOfNodes();
	void addNode(Node node);
};

