#include "node.h"

Node::Node(int data) {
	this -> data = data;
	left = NULL;
	right = NULL;
}

Node::~Node() {
}

void Node::setData(int data) {
	this -> data = data;
}

int Node::getData() {
	return data;
}

void Node::setLeft(Node* left) {
	this -> left = left;
}

Node* Node::getLeft() {
	return left;
}

void Node::setRight(Node* right) {
	this -> right = right;
}

Node* Node::getRight() {
	return right;
}
