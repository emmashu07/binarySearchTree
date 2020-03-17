#include <iostream>
#include <cstring> 
#include <cmath>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int convertToInt(char* num);
int inputToInt(char* input, int* array);
int fileToInt(char* fileName, int* array);
void add(Node* &currRoot, int num);
bool search(Node* currRoot, int num);
//void print(Node* currRoot, int tabNum);
void build(int* array, int size, Node* &root);
bool remove(Node* &currRoot, int num); 
void removeNode(Node* &currRoot);
void display(Node* currRoot);

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
		
		if (strcmp(input2, "INSERT") == 0) {
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cin.ignore(20, '\n');
			add(root, num);
		}
		else if (strcmp(input2, "SEARCH") == 0) {
			bool in;
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cout << endl;
			cin.ignore(20, '\n');
			in = search(root, num);
			if (in) {
				cout << "The number is in the tree." << endl;
			}
			else {
				cout << "The number is not in the tree." << endl;
			}	
		}
		else if (strcmp(input2, "REMOVE") == 0) {
			bool in;
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cout << endl;
			cin.ignore(20, '\n');
			in = remove(root, num);
			if (in) {
				cout << "Deleted." << endl;
			}
			else {
				cout << "The number is not in the tree." << endl;
			}
		}	
		else if (strcmp(input2, "PRINT") == 0) {
			//print(root, 0);
			display(root);
			cout << endl;
		}
		else if (strcmp(input2, "QUIT") == 0) {
			running = false;
		}
	}
	

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
	int arrayIndex = 0;
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
		currRoot = new Node();
		currRoot -> data = num;
	}
	else if (num < currRoot -> data) {
		add(currRoot -> left, num);
	}
	else if (num > currRoot -> data) {
		add(currRoot -> right, num);	
	}
}

bool search(Node* currRoot, int num) {
	if (!currRoot) {
		return false;
	}
	else if (currRoot -> data == num) {
		return true;
	}
	else if (currRoot -> data > num) {
		return search(currRoot -> left, num);
	}
	else if (currRoot -> data < num) {
		return search(currRoot -> right, num);
	}
}

void removeNode(Node* &node) {
	if (!(node -> left) && !(node -> right)) {
		delete node;
		node = NULL;
	}
	else if (node -> left) {
		Node* temp = node -> right;
		delete node;
		node = temp;
	}
	else if (node -> right) {
		Node* temp = node -> left;
		delete node;
		node = temp;
	}
	else {
		Node* temp = node -> left;
		while (temp -> right) {
			temp = temp -> right;
		}
		delete node;
		node = temp;
	}
}

bool remove(Node* &currRoot, int num) {
	if (!currRoot) {
		return false;
	}
	else if (num < currRoot -> data) {
		return remove(currRoot -> left, num);
	}
	else if (num > currRoot -> data) {
		return remove(currRoot -> right, num);
	}
	else if (num == currRoot -> data) {
		return true;
		removeNode(currRoot);
	}
}
	

void build(int* array, int size, Node* &root) {
	for (int i = 0; i < size; i++) {
		add(root, array[i]);
	}
}

/*void print(Node* currRoot, int tabNum) {
	if (currRoot -> left) {
		print(currRoot -> left, tabNum+1);
	}
	int i = 0;
	while (i < tabNum) {
		cout << '\t';
		i++;
	}
	cout << currRoot -> data << endl;
	if (currRoot -> right) {
		print(currRoot -> right, tabNum+1);
	}
	
}*/

void display(Node* currRoot) {
	if (currRoot) {
		display(currRoot -> left);
		cout << currRoot -> data << ' ';
		display(currRoot -> right);
	}
}

