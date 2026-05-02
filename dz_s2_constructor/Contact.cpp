#include "Phonebook.h"

void Contact::setName(char* name)
{
	if (name != nullptr)
	{
		delete[] this->pib.name;
		this->pib.name = new char[strlen(name) + 1];
		strcpy_s(this->pib.name, strlen(name) + 1, name);
	}
}

void Contact::setSurname(char* surname)
{
	if (surname != nullptr)
	{
		delete[] this->pib.surname;
		this->pib.surname = new char[strlen(surname) + 1];
		strcpy_s(this->pib.surname, strlen(surname) + 1, surname);
	}
}

void Contact::setFather(char* father)
{
	if (father != nullptr)
	{
		delete[] this->pib.father;
		this->pib.father = new char[strlen(father) + 1];
		strcpy_s(this->pib.father, strlen(father) + 1, father);
	}
}

void Contact::setDescription(char* description)
{
	if (description != nullptr)
	{
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}
}

void Contact::setNumberHome(char* number)
{
	if (number != nullptr && strlen(number) <= 10)
		strcpy_s(this->number.home, 11, number);
}

void Contact::setNumberWork(char* number)
{
	if (number != nullptr && strlen(number) <= 10)
		strcpy_s(this->number.work, 11, number);
}

void Contact::setNumberMobile(char* number)
{
	if (number != nullptr && strlen(number) <= 10)
		strcpy_s(this->number.mobile, 11, number);
}


const char* Contact::getName() const { return pib.name; }
const char* Contact::getSurname() const { return pib.surname; }
const char* Contact::getFather() const { return pib.father; }
const char* Contact::getNumberHome() const { return number.home; }
const char* Contact::getNumberWork() const { return number.work; }
const char* Contact::getNumberMobile() const { return number.mobile; }
const char* Contact::getDescription() const { return description; }


void Contact::show()
{
	std::cout <<
		"==============================" <<
		"\nName: " << pib.name <<
		"\nSurname: " << pib.surname <<
		"\nFather: " << pib.father <<
		"\n" <<
		"\nHome number: " << number.home <<
		"\nWork number: " << number.work <<
		"\nMobile number: " << number.mobile <<
		"\n" <<
		"\nDescription: " << description <<
		std::endl;
}