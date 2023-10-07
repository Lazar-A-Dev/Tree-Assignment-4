#include "Node.h"
Node::Node() {
	left = right = parent = NULL;
	info = 0;
}

Node::Node(int info) {
	left = right = parent = NULL;
	this->info = info;
}

Node::~Node() {

}

void Node::Print() {
	cout << GetInfo() << " ";
}
