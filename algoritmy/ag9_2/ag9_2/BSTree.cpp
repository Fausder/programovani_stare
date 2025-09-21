#include "BSTree.h"
#include <iostream>

using namespace std;
void BSTree::insert(int value)
{
	this->insert(this->root, value);
}

void BSTree::insert(Node*& root, int value)
{
	if (root == nullptr)
	{
		root = new Node(value);
		return;
	}
	if (value < root->value)
	{
		insert(root->left, value);
	}
	if (value > root->value)
	{
		insert(root->right, value);
	}
}

int BSTree::weAreGroot()
{
	return this->weAreGroot(this->root);
}

int BSTree::weAreGroot(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return 1 + weAreGroot(root->left) + weAreGroot(root->right);
}


void BSTree::printSorted(bool asc)
{
	this->printSorted(this->root, asc);
}
void BSTree::printSorted(Node* root, bool asc)
{
	if (root == nullptr)
	{
		return;
	}
	printSorted(root->left, asc); // Opraveno poøadí argumentù
	cout << root->value << " ";
	printSorted(root->right, asc); // Opraveno poøadí argumentù
}
BSTree::Node* BSTree::getRoot()
{
	return this->root;
}

int BSTree::height(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return max(leftHeight, rightHeight) + 1;
}	

bool BSTree::isBalanced(Node* root)
{
	if (root == nullptr)
	{
		return true;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (abs(leftHeight - rightHeight) > 1)
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}

// Implementace metody insertionSort
void BSTree::insertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		// Posun prvkù vìtších než key o jednu pozici doprava
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


bool isSortedAsc(int* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
}

bool BSTree::isSorted(int* arr, int size) {
	// Kontrola, zda je pole seøazeno ve vzestupném poøadí
	if (size <= 1) {
		return true; // Jednoprvkové nebo prázdné pole je vždy seøazené
	}
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

int BSTree::kthLargest(int* arr, int N, int k)
{
	if (k > N)
	{
		return -1;
	}
	// Oprava: Volání insertionSort bez použití 'this', protože metoda je èlenem instance
	insertionSort(arr, N);
	return arr[N - k];
}
