#include<iostream>

using namespace std;

class Node {
	public:
		Node(int data);
		~Node();
		int getData();
		void setData(int data);
		Node* getLeft();
		void setLeft(Node* left);
		Node* getRight();
		void setRight(Node* right);
	private:
		int data;
		Node* left;
		Node* right;
}
