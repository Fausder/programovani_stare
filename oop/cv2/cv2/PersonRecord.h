#pragma once
#include <string>

using String = std::string;

enum Sex
{
	male = 0,
	female = 1
};

class PersonRecord
{
private:
	std::string name;
	std::string birthNumber;
public:
	PersonRecord(std::string person_name, std::string birthNr);
	std::string GetName();
	std::string GetBirthDate();
	Sex GetSex();
};
