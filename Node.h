#pragma once

#include <map>
#include<utility>

class Node
{
private :
	unsigned id;
	std::pair<int, int> coordinates; //in this case all the coordinates are unsigned but prefer using Int instead
	std::map<Node, int>* edges;

public :
	Node(unsigned id, std::pair<int, int> coordinates);
	unsigned getID() const;
	std::pair<int, int> getCoordinates();
	std::map<Node, int>* getEdges();
	void addEdge(Node neighbour, int weight);
	bool operator < (Node node2) const; //Visual is sending and error if not overloading this operator

}; //Node
