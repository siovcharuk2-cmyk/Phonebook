#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Contact.h"
#include <cstdio>

class Phonebook

{
private:
	Contact* contacts;
	int size;

public:
	Phonebook(const Contact* contacts, const int size)
		: size{ size }
	{
		this->contacts = new Contact[size];
		for (int i = 0; i < size; i++)
			this->contacts[i] = contacts[i];
	}

	Phonebook() : Phonebook{ nullptr, 0 } {}

	~Phonebook()
	{
		delete[] contacts;
	}


	// methods
	void add();
	void del();
	void find();
	void show();
	void save();
	void load();
};