#include <iostream>
#include <cstring> 
#include <cmath>
#include "node.h"

int convertToInt(char* num);
void inputToInt(char* input, int* array);
void fileToInt(char* fileName, int* array);
void add(Node* &currRoot, int num);
bool search(Node* currRoot, int num);
void build(int* array, int size, Node* &root);

int main() {
	char input[200];
	char fileName[50];
	char forC[10];
	char input2[20];
	int* array = new int[100];
	int size;
	Node* root = NULL;
	bool running = true;

	cout << "Please enter whether you would like to input through file or console: ";
	cin.get(forC, 10);
	cin.ignore(10, '\n');

	if (strcmp(forC, "FILE") == 0) {
		cout << "Please enter a file name: ";
		cin.get(fileName, 50);
		cin.ignore(50, '\n');
		size = fileToInt(fileName, array);
	}
	else if (strcmp(forC, "CONSOLE") == 0) {
		cout << "Please enter a series of numbers separated by a space: ";
		cin.get(input, 200);
		cin.ignore(200, '\n');
		size = inputToInt(input, array);	
	}
	else {
		cout << "Please enter FILE or CONSOLE." << endl;
	}	

	build(array, size, root);

	while (running) {
	cout << "Please enter whether you would like to search, remove, insert, print, or quit: ";
	cin.get(input2, 20);
	cin.ignore(20, '\n');
	

	return 0;
}

int convertToInt(char* num) { // Using a char array, make an int.
	int fin = 0;
	int power = strlen(num) - 1;
	for (int i = 0; i < strlen(num); i++) {
		int digit = num[i] - '0';
		fin += digit * pow(10, power-i);
	}
	return fin;
}

int inputToInt(char* input, int* array) { // Take the input and convert it into an int array.
	int arrayIndex = 1;
	array[0] = -1;
	for (int i = 0; i < strlen(input); i++) {
		if (!isspace(input[i]) && isdigit(input[i])) {
			int index = 0;
			char* num = new char[3];
			num[index] = input[i];
			index++;
			while (!isspace(input[i+1])) {
				i++;
				num[index] = input[i];
			        index++;
			}
			num[index] = '\0';
			array[arrayIndex] = convertToInt(num);
		        arrayIndex++;
		}
	}
	return arrayIndex;
}

int fileToInt(char* fileName, int* array) { // File input to int array, utilizes input to int.
	char input[200];
	int size;
	ifstream file(fileName);
	if (file.is_open()) {
		file.getline(input, 200);
		file.close();
		size = inputToInt(input, array);	
		return size;
	}
	else {
		cout << "Unable to open file." << endl;
		return -1;
	}
}	

void add(Node* &currRoot, int num) {
	if (!currRoot) { 
		currRoot = new Node(num);
	}
	else if (num < currRoot -> getData()) {
		add(currRoot -> getLeft(), num);
	}
	else if (num > currRoot -> getData()) {
		add(currRoot -> getRight(), num);	
	}
}

bool search(Node* currRoot, int num) {
	if (!currRoot) {
		return false;
	}
	else if (currRoot -> getData() == num) {
		return true;
	}
	else if (currRoot -> getData() < num) {
		return search(currRoot -> getLeft(), num);
	}
	else if (currRoot -> getData() > num) {
		return search(currRoot -> getRight(), num);
	}
}

bool remove(Node* &currRoot, int num, Node* root) {
	if (!currRoot) {
		return false;
	}
	else if (num < currRoot -> getData()) {
		return remove(currRoot -> getLeft(), num, root);
	}
	else if (num > currRoot -> getData()) {
		return remove(currRoot -> getRight(), num, root);
	}
	else if (num == currRoot -> getData()) {
		return true;
		removeNode(currRoot, root);
	}
	

void build(int* array, int size, Node* &root) {
	for (int i = 0; i < size; i++) {
		add(root, array[i]);
	}
}			
