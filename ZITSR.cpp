#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <array>

using namespace std;

int showmenu ();
void login (bool &, bool &);
void add_pupil ();
void display_student_details ();

const int max_rows = 5;
const int max_column = 6;

string student_details[max_rows][max_column];


int main ()
{
    system("cls");

    int option;
    bool loged_in_As_Ad = false, loged_in = false;

    login(loged_in_As_Ad, loged_in);

    if(loged_in == true || loged_in_As_Ad == true)
    {
        do
        {
            option = showmenu();
            switch (option)
            {
                case 1:
                if(loged_in_As_Ad)
                {
                    add_pupil();
                    system("cls");
                }
                break;

                case 2:
                cout << "Delete" << endl;
                break;

                case 3:
                cout << "Search" << endl;
                break;

                case 4:
                cout << "Edit" << endl;
                break;

                case 5:
                system("cls");
                display_student_details();
                getch();
                system("cls");
                break;

                case 6:
                cout << "Exit" << endl;
                break;

            }
        } while (option!=6);

    }



    return 0;
}

void login (bool &loged_in_as_Ad, bool &loged_in)
{
    int user_password, password1, password2, password3, password4;


    ifstream credentials("credentials.txt");

    while(credentials>>password1>>password2>>password3>>password4)

    credentials.close();

    do
    {
        cout<<"Enter the Password: ";
        cin>>user_password;

        if(user_password == password1 ||user_password == password2)
        {
            loged_in_as_Ad = true;
            return;
        }

        else if(user_password == password3 || user_password == password4)
        {
            loged_in = true;
            return;
        }

        else
        {
            cout<<"Access Denied!\n";
            getch();
            system("cls");
    }

    } while(loged_in == false && loged_in_as_Ad == false);


}

int showmenu ()
{
    int opt;

    cout<<setw(45)<< "Main Menu\n";
    cout<<"Press: \n";
    cout<<"1. To add new pupil\n";
    cout<<"2. To delete pupil\n";
    cout<<"3. To search for pupil\n";
    cout<<"4. To edit pupil record\n";
    cout<<"5. To display all pupils by grade\n";
    cout<<"6. To exit\n";

    cout<<"\nchoice: ";
    cin>>opt;

    if(opt>6||opt<1)
    {
        cout<<"Invalid option\n";
        getch();
        system ("cls");
        showmenu();
    }

    return opt;
}

void add_pupil ()
{
    char choice;

    system("cls");

    for(int counter = 0; counter < max_rows; counter++)
    {
        cout<<"Enter student ID: "; cin>>student_details[counter][0];
        cout<<"Enter first name: "; cin>>student_details[counter][1];
        cout<<"Enter surname: "; cin>>student_details[counter][2];
        cout<<"Enter age: "; cin>>student_details[counter][3];
        cout<<"Enter grade: "; cin>>student_details[counter][4];
        cout<<"Enter guardians phone number: "; cin>>student_details[counter][5];

        cout<<"\nPress Y to continue or N to save student details and go back to the main menu: "; cin>>choice;

        if(choice == 'y' || choice == 'Y')
            continue;
        else
            return;
    }

}

void display_student_details()
{
    cout << "===============================================================================================\n";

    cout<<left<<setw(15)<<"Pupil ID"<<left<<setw(15)<<"First name"<<left<<setw(15)<<"surname"<<left<<setw(15)<<"Age"<<left<<setw(15)<<"Grade"<<left<<setw(15)<<"Guardians cell number"<<endl;

    cout << "===============================================================================================\n";

    for(int rows = 0; rows < max_rows; rows++)
    {

        for(int columns = 0; columns < max_column; columns++)
        {
            cout<<left<<setw(15)<<student_details[rows][columns];
        }

        cout<<endl;

    }
    
    //cout << "===============================================================================================\n";
}
