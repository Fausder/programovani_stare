#include <iostream>
#include "BSTree.h" 

using namespace std;

int main()
{
	BSTree groot;

	groot.insert(10);
	groot.insert(5);
	groot.insert(30);
	groot.insert(2);
	groot.insert(7);
	groot.insert(20);
	groot.insert(40);
	groot.insert(15);
	groot.insert(25);
	groot.insert(35);
	groot.insert(23);
	groot.insert(27);

	cout << groot.weAreGroot() << endl;
	groot.printSorted(true);
	groot.height(groot.getRoot());

	return 0;
}