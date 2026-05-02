#include <iostream>
#include "Phonebook.h"

int main()
{
    Phonebook pbook;
    void (Phonebook:: *option[6])() =
    {
        &Phonebook::add,
        &Phonebook::del,
        &Phonebook::find,
        &Phonebook::show,
        &Phonebook::save,
        &Phonebook::load
    };


    while (true)
    {
        short choice;
        std::cout <<
            "\n1. Add new contact" <<
            "\n2. Delete contact" <<
            "\n3. Find contact" <<
            "\n4. Show all contacts" <<
            "\n5. Save as phonebook" <<
            "\n6. Load phonebook" <<
            "\n0. Exit" <<
            "\n> ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        if (choice == 0) return 0;

        (pbook.*option[choice - 1])();
    }
}