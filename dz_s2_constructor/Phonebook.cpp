#include "Phonebook.h"
#include <iostream>
#include <cstring>

void Phonebook::add()
{
	Contact* temp = new Contact[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = contacts[i];

	char buffer[2048];
	std::cout << "Enter name: ";
	std::cin.getline(buffer, 64);
	temp[size].setName(buffer);
	std::cout << "Enter surname: ";
	std::cin.getline(buffer, 64);
	temp[size].setSurname(buffer);
	std::cout << "Enter father: ";
	std::cin.getline(buffer, 64);
	temp[size].setFather(buffer);
	std::cout << "Enter home number: ";
	std::cin.getline(buffer, 11);
	temp[size].setNumberHome(buffer);
	std::cout << "Enter work number: ";
	std::cin.getline(buffer, 11);
	temp[size].setNumberWork(buffer);
	std::cout << "Enter mobile number: ";
	std::cin.getline(buffer, 11);
	temp[size].setNumberMobile(buffer);
	std::cout << "Enter description: ";
	std::cin.getline(buffer, 2048);
	temp[size].setDescription(buffer);

	delete[] contacts;
	contacts = temp;
	size++;
	std::cout << "Contact added!\n";
}

void Phonebook::del()
{
	char buffer[11];
	std::cout << "Enter any number: ";
	std::cin.getline(buffer, 11);

	int del_index;
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].getNumberHome(), buffer) == 0 ||
			strcmp(contacts[i].getNumberWork(), buffer) == 0 ||
			strcmp(contacts[i].getNumberMobile(), buffer) == 0)
		{
			del_index = i;
			found = true;
			break;
		}
	}

	if (!found)
	{
		std::cout << "Contact not found!";
		return;
	}

	Contact* temp = new Contact[size - 1];

	for (int i = 0; i < del_index; i++)
		temp[i] = contacts[i];

	for (int i = del_index + 1; i < size; i++)
		temp[i - 1] = contacts[i];

	delete[] contacts;
	contacts = temp;
	size--;
	std::cout << "Contact deleted!\n";
}

void Phonebook::find()
{
	char name[64];
	char surname[64];
	char father[64];

	std::cout << "Enter name: ";
	std::cin.getline(name, 64);
	std::cout << "Enter surname: ";
	std::cin.getline(surname, 64);
	std::cout << "Enter father: ";
	std::cin.getline(father, 64);

	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].getName(), name) == 0 &&
			strcmp(contacts[i].getSurname(), surname) == 0 &&
			strcmp(contacts[i].getFather(), father) == 0)
		{
			found = true;
			contacts[i].show();
			std::cout << std::endl;
		}
	}

	if (!found)
		std::cout << "Contact not found!";
}

void Phonebook::show()
{
	if (size == 0)
	{
		std::cout << "Empty\n";
		return;
	}

	for (int i = 0; i < size; i++)
	{
		contacts[i].show();
		std::cout << std::endl;
	}
}

void Phonebook::save()
{
	FILE* file = fopen("./saves.txt", "w");

	if (file == nullptr)
	{
		std::cout << "Error opening file!\n";
		return;
	}

	fprintf(file, "%d\n", size);

	for (int i = 0; i < size; i++)
	{
		fputs(contacts[i].getName() ? contacts[i].getName() : "-", file);
		fputs("\n", file);

		fputs(contacts[i].getSurname() ? contacts[i].getSurname() : "-", file);
		fputs("\n", file);

		fputs(contacts[i].getFather() ? contacts[i].getFather() : "-", file);
		fputs("\n", file);

		fputs(contacts[i].getNumberHome(), file);
		fputs("\n", file);

		fputs(contacts[i].getNumberWork(), file);
		fputs("\n", file);

		fputs(contacts[i].getNumberMobile(), file);
		fputs("\n", file);

		fputs(contacts[i].getDescription() ? contacts[i].getDescription() : "-", file);
		fputs("\n", file);
	}

	fclose(file);
	std::cout << "Saved successfully\n";
}

void Phonebook::load()
{
	FILE* file = fopen("./saves.txt", "r");
	if (file == nullptr)
	{
		std::cout << "Error opening file!\n";
		return;
	}

	int new_size = 0;
	if (fscanf(file, "%d\n", &new_size) != 1)
	{
		fclose(file);
		return;
	}

	delete[] contacts;
	size = new_size;
	contacts = new Contact[size];

	char buffer[2048];

	auto read_line = [&](char* dest, int max_size)
	{
		if (fgets(buffer, 2048, file))
		{
			buffer[strcspn(buffer, "\r\n")] = '\0';
			if (strcmp(buffer, "-") == 0) buffer[0] = '\0';

			strncpy(dest, buffer, max_size);
			dest[max_size - 1] = '\0';
		}
	};

	for (int i = 0; i < size; i++)
	{
		char f_name[64], f_surname[64], f_father[64];
		char f_home[11], f_work[11], f_mobile[11];
		char f_desc[2048];

		read_line(f_name, 64);
		read_line(f_surname, 64);
		read_line(f_father, 64);
		read_line(f_home, 11);
		read_line(f_work, 11);
		read_line(f_mobile, 11);
		read_line(f_desc, 2048);

		Pib tempPib(f_name, f_surname, f_father);
		Number tempNum;
		strcpy_s(tempNum.home, 11, f_home);
		strcpy_s(tempNum.work, 11, f_work);
		strcpy_s(tempNum.mobile, 11, f_mobile);

		contacts[i] = Contact(tempPib, tempNum, f_desc);
	}

	fclose(file);
	std::cout << "Loaded " << size << " contacts.\n";
}