#include "Node.h"
#include <string>

Node::Node(unsigned id, std::pair<int, int> coordinates) : id(id), coordinates(coordinates) {
	edges = new std::map<Node, int>();
}

unsigned Node::getID() const {
	return id;
}

std::pair<int, int> Node::getCoordinates() {
	return coordinates;
}

std::map<Node, int>* Node::getEdges() {
	return edges;
}

void Node::addEdge(Node neighbour, int weight) {
	edges->insert(std::pair<Node, int>(neighbour, weight));
}

bool Node::operator < (Node node2) const{
	return this->getID() < node2.getID();
}