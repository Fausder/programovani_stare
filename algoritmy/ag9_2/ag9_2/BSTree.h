#pragma once
class BSTree
{
private:
	class Node
	{
	public:
		int value;	
		Node* left = nullptr;
		Node* right = nullptr;
		Node(int val) {
			this->value = val;
		}
	};
	Node* root = nullptr;
	void insert(Node*& root, int value);
	void printSorted(Node* root, bool asc);
public:
	void insert(int value);
	int weAreGroot();
	int weAreGroot(Node* root);
	void printSorted(bool asc);
	Node* getRoot(); // Pøidána metoda pro pøístup k root
	int height(Node* root);
	bool isBalanced(Node* root);

	void insertionSort(int* arr, int size);

	bool isSorted(int* arr, int size);
	int kthLargest(int* arr, int size, int k);



};