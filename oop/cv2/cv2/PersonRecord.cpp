#include "PersonRecord.h"
#include <iostream>

PersonRecord::PersonRecord(String person_name, String birthNr)
{
	this->name = person_name;
	this->birthNumber = birthNr;
}

String PersonRecord::GetName()
{
	return this->name;
}

String PersonRecord::GetBirthDate()
{
	return this->birthNumber;
}

Sex PersonRecord::GetSex()
{
	if (this->birthNumber[2] == '5' || this->birthNumber[2] == '6')
	{
		return female;
	}
	else
	{
		return male;
		
	}
}
