#pragma once
#include <iostream>

class AbstractAccount
{
public:
	AbstractAccount();
	virtual ~AbstractAccount();
	virtual bool canWithdraw(double a) = 0;
};