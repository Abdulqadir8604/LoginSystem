#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

bool isLoggesIN()
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read("D:/C++ projects(eclipse)/LoginSystem" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int choice;

    cout << "1: Register\n2: Login\nYour Choice: ";
    cin >> choice;
    if(choice == 1)
    {
        string username, password;
        cout<< "Select user name: ";
        cin >> username;

        cout<< "Select password: ";
        cin >> password;

        ofstream file;
        file.open("D:/C++ projects(eclipse)/LoginSystem" + username + ".txt");
        file << username << endl << password;
        file.close();

        main ();
    }
    else if(choice == 2)
    {
        bool status = isLoggesIN();
        if(!status)
        {
            cout << "False Login!" <<endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successfully Logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}

