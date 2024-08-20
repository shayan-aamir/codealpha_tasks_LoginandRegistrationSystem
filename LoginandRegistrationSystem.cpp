#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

void registerUser()
{
    string username, password;
    char ch;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    ch = _getch();
    while (ch != 13)
    {
        if (ch != 8)
        {
            password.push_back(ch);
            cout << '*';
        }
        else if (!password.empty())
        {
            password.pop_back();
            cout << "\b \b";
        }
        ch = _getch();
    }

    ofstream file;
    file.open("database.txt", ios::app);
    file << "USername:" << username << " Password: " << password << endl;
    file.close();

    cout << "\nRegistration successful!\n";
}

bool loginUser()
{
    string username, password, u, p;
    char ch;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    ch = _getch();
    while (ch != 13)
    {
        if (ch != 8)
        {
            password.push_back(ch);
            cout << '*';
        }
        else if (!password.empty())
        {
            password.pop_back();
            cout << "\b \b";
        }
        ch = _getch();

        ifstream file("database.txt");
        while (file >> u >> p)
        {
            if (u == username && p == password)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
}

int main()
{
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser();
    }
    else if (choice == 2)
    {
        if (loginUser())
        {
            cout << "\nLogin successful!\n";
        }
        else
        {
            cout << "\nInvalid username or password.\n";
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}
