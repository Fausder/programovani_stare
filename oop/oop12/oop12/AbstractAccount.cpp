#include "AbstractAccount.h"
#include <iostream>

using namespace std;

AbstractAccount::AbstractAccount()
{
	cout << "AbstractAccount constructor" << endl;
}

AbstractAccount::~AbstractAccount()
{
	cout << "AbstractAccount destructor" << endl;
}