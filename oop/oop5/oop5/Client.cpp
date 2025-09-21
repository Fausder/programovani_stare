#include "Client.h"

using namespace std;

Client::Client(int c, string n)
{
	code = c;
	name = n;
}

int Client::GetCode()
{
	return code;
}

string Client::GetName()
{
	return name;
}