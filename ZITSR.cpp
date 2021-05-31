#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main_menu(); // declare prototype
void login(bool &, bool &);
void Add();

int main()
{
    int option;
    bool loged_in_as_Ad = false, logedin = false;

    login(loged_in_as_Ad, logedin);

    if(loged_in_as_Ad || logedin)
    {
        system("cls");
        option = main_menu();

        switch (option)
        {
        case 1:
            if(loged_in_as_Ad)
                Add();
            else
            {
                cout<<"You don't have access to this option\n";
                system("PAUSE");
                system ("cls");
                main_menu();
            }
            break;

        }
    }


    return 0;
}

void login(bool &loged_in_as_AD, bool &logedin)
{
    int password, password1, password2, password3, password4;

    ifstream credentials("credentials.txt");

    while(credentials>>password1>>password2>>password3>>password4)

    credentials.close();

    do
    {
        cout<<"Login with your password\n";
        cout<<"password: "; cin>>password;

        if(password == password1 || password == password2)
        {
            loged_in_as_AD = true;
            return;
        }
        else if(password == password3 || password == password4)
        {
            logedin = true;
            return;
        }
        else
        {
            cout<<"Incorrect password. try again\n";
        }

    }while(loged_in_as_AD == false && logedin == false);

}

int main_menu()
{
    int option;

    cout<<"Press:\n";
	cout<<"1. Add New Pupil\n";
	cout<<"2. Delete Pupil\n";
	cout<<"3. Search For Pupil\n";
	cout<<"4. Edit Pupil Record\n";
	cout<<"5. Display All Pupils By Grade\n";
	cout<<"6. Exit\n";
	cin>>option;

	if(option > 6 || option < 1)
    {
        cout<<"Invalid option\n";
        main_menu();
    }

    return option;
}

void Add()
{
    /*ofstream students("students.txt");

    students<<left<<setw(20)<<"student ID"<<left<<setw(30)<<"first name"<<left<<setw(30)<<"surname"<<left<<setw(15)<<"Age"<<left<<setw(15)<<"Grade"<<left<<setw(20)<<"Guardians number"<<endl;

    students.close();*/

}
