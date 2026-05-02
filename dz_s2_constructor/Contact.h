#pragma once
#include <cstring>
#include <iostream>

struct Pib
{
	char* name;
	char* surname;
	char* father;

	Pib(const char* n, const char* s, const char* f)
		: name{ n ? new char[strlen(n) + 1] : nullptr },
		  surname{ s ? new char[strlen(s) + 1] : nullptr },
		  father{ f ? new char[strlen(f) + 1] : nullptr }
	{
		if (name) strcpy_s(name, strlen(n) + 1, n);
		if (surname) strcpy_s(surname, strlen(s) + 1, s);
		if (father) strcpy_s(father, strlen(f) + 1, f);
	}

	Pib(const Pib& other)
		: Pib{ other.name, other.surname, other.father }
	{ }

	Pib& operator=(const Pib& other)
	{
		if (this != &other)
		{
			delete[] name;
			delete[] surname;
			delete[] father;

			name = other.name ? _strdup(other.name) : nullptr;
			surname = other.surname ? _strdup(other.surname) : nullptr;
			father = other.father ? _strdup(other.father) : nullptr;
		}
		return *this;
	}

	~Pib()
	{
		delete[] name;
		delete[] surname;
		delete[] father;
	}
};

struct Number
{
	char home[11];
	char work[11];
	char mobile[11];
};

class Contact
{
	Pib pib;
	Number number;
	char* description;

public:
	Contact(const Pib& p, const Number& n, const char* d)
		: pib{ p },
		number{ n },
		description{ d ? new char[strlen(d) + 1] : nullptr }
	{
		if (description) strcpy_s(description, strlen(d) + 1, d);
	}

	Contact() : Contact
	{
		{nullptr, nullptr, nullptr},
		{"0000000000", "0000000000", "0000000000"},
		nullptr
	}
	{ }

	Contact(const Contact& other)
		: pib(other.pib),
		number(other.number),
		description(other.description ? new char[strlen(other.description) + 1] : nullptr)
	{
		if (description) strcpy_s(description, strlen(other.description) + 1, other.description);
	}

	Contact& operator=(const Contact& other)
	{
		if (this != &other)
		{
			delete[] description;

			this->pib = other.pib;
			this->number = other.number;

			this->description = other.description ? _strdup(other.description) : nullptr;
		}
		return *this;
	}

	~Contact()
	{
		delete[] description;
	}


	void setName(char* name);
	void setSurname(char* surname);
	void setFather(char* father);
	void setNumberHome(char* number);
	void setNumberWork(char* number);
	void setNumberMobile(char* number);
	void setDescription(char* description);

	const char* getName() const;
	const char* getSurname() const;
	const char* getFather() const;
	const char* getNumberHome() const;
	const char* getNumberWork() const;
	const char* getNumberMobile() const;
	const char* getDescription() const;

	void show();
};