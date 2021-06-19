#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
using namespace std;

int showmenu ();
void login (bool &, bool &);
void add_pupil ();
void display_student_details ();
void update_file();
void edit();
void search();
void retrieve_data();

struct student_details
{
    string first_name;
    string surname;
    int student_ID;
    int age;
    int grade;
    int guardians_phone_number;
};
const int MAX_ROWS = 10;
student_details students[MAX_ROWS];


int main ()
{
    system("cls");

    int option;
    bool loged_in_As_Administrator = false, loged_in = false;

    retrieve_data();

    login(loged_in_As_Administrator, loged_in);

    if(loged_in == true || loged_in_As_Administrator == true)
    {
        system("cls");
        
        do
        {
            option = showmenu();
            switch (option)
            {
                case 1:
                if(loged_in_As_Administrator)
                {
                    add_pupil();
                    system("cls");
                }
                break;

                case 2:
                cout << "Delete" << endl;
                break;

                case 3:
                system("cls");
                search();
                getch();
                break;

                case 4:
                system("cls");
                edit();
                getch();
                system("cls");
                break;

                case 5:
                system("cls");
                display_student_details();
                getch();
                system("cls");
                break;

                case 6:
                update_file();
                exit(0);
                break;

            }
        } while (option!=6);

    }



    return 0;
}


void login (bool &loged_in_as_Administrator, bool &loged_in)
{
    int user_password, password1, password2, password3, password4;


    ifstream credentials("credentials.txt");

    if(credentials)
    {
        while(credentials>>password1>>password2>>password3>>password4)

        credentials.close();
        
        do
        {
            cout<<"Enter the Password: ";
            cin>>user_password;

            if(user_password == password1 ||user_password == password2)
            {
                loged_in_as_Administrator = true;
                return;
            }

            else if(user_password == password3 || user_password == password4)
            {
                loged_in = true;
                return;
            }

            else
            {
                system("cls");
                cout<<"Access Denied! invalid username or password\n\n";
                cout<<"Press any key to try again";
                getch();
                system("cls");
            }

        } while(loged_in == false && loged_in_as_Administrator == false);


    }

    else
    {
        cerr<<"error opening credentials file!\n";
        getch();
        exit(1)
    }

    
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

    for(int row = 0; row < MAX_ROWS; row++)
    {
        cout<<"Enter student ID: "; cin>>students[row].student_ID;
        cout<<"Enter first name: "; cin>>students[row].first_name;
        cout<<"Enter surname: "; cin>>students[row].surname;
        cout<<"Enter age: "; cin>>students[row].age;
        cout<<"Enter grade: "; cin>>students[row].grade;
        cout<<"Enter guardians phone number: "; cin>>students[row].guardians_phone_number;

        cout<<"\nPress Y to continue or any key to save student details and go back to the main menu: "; cin>>choice;

        system("cls");

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

    for(int rows = 0; rows < MAX_ROWS; rows++)
    {
        if(students[rows].student_ID != 0)
        {
            cout<<left<<setw(15)<<students[rows].student_ID;
            cout<<left<<setw(15)<<students[rows].first_name;
            cout<<left<<setw(15)<<students[rows].surname;
            cout<<left<<setw(15)<<students[rows].age;
            cout<<left<<setw(15)<<students[rows].grade;
            cout<<left<<setw(15)<<students[rows].guardians_phone_number<<endl;
        }

        else
        {
            break;
        }

    }
    
    cout << "===============================================================================================\n";

}


void update_file()
{
    ofstream inputfile;
    inputfile.open("students.txt");

    inputfile<<left<<setw(15)<<"Pupil ID"<<left<<setw(15)<<"First name"<<left<<setw(15)<<"surname"<<left<<setw(15)<<"Age"<<left<<setw(15)<<"Grade"<<left<<setw(15)<<"Guardians cell number"<<endl;

    for(int row = 0; row < MAX_ROWS; row++)
    {
        inputfile<<left<<setw(15)<<students[row].student_ID;
        inputfile<<left<<setw(15)<<students[row].first_name;
        inputfile<<left<<setw(15)<<students[row].surname;
        inputfile<<left<<setw(15)<<students[row].age;
        inputfile<<left<<setw(15)<<students[row].grade;
        inputfile<<left<<setw(15)<<students[row].guardians_phone_number<<endl;
    }

    inputfile.close();
} 


void search()
{
    int ID;

    cout<<"Enter student ID: "; cin>>ID;

    for(int row = 0; row < MAX_ROWS; row++)
    {
        if(ID == students[row].student_ID)
        {
            cout << "===============================================================================================\n";

            cout<<left<<setw(15)<<"Pupil ID"<<left<<setw(15)<<"First name"<<left<<setw(15)<<"surname"<<left<<setw(15)<<"Age"<<left<<setw(15)<<"Grade"<<left<<setw(15)<<"Guardians cell number"<<endl;

            cout << "===============================================================================================\n";

            cout<<left<<setw(15)<<students[row].student_ID<<left<<setw(15)<<students[row].first_name<<left<<setw(15)<<students[row].surname<<left<<setw(15)<<students[row].age<<left<<setw(15)<<students[row].grade<<left<<setw(15)<<students[row].guardians_phone_number<<endl;

            cout << "===============================================================================================\n";

        }
    }
}


void edit()
{
    int ID;
    int option;
    int row = 0;

    cout<<"Enter student ID: "; cin>>ID;

    for(row < MAX_ROWS; row++;)
    {
        if(ID == students[row].student_ID)
        {
            cout << "===============================================================================================\n";

            cout<<left<<setw(15)<<"Pupil ID"<<left<<setw(15)<<"First name"<<left<<setw(15)<<"surname"<<left<<setw(15)<<"Age"<<left<<setw(15)<<"Grade"<<left<<setw(15)<<"Guardians cell number"<<endl;

            cout << "===============================================================================================\n";

            cout<<left<<setw(15)<<students[row].student_ID<<left<<setw(15)<<students[row].first_name<<left<<setw(15)<<students[row].surname<<left<<setw(15)<<students[row].age<<left<<setw(15)<<students[row].grade<<left<<setw(15)<<students[row].guardians_phone_number<<endl;

            cout << "===============================================================================================\n";

        }

    }

    cout << "Press: \n";
    cout << "1. To edit ID Number"<< endl;
    cout << "2. To edit First name"<< endl;
    cout << "3. To edit Surname"<< endl;
    cout << "4. To edit age "<< endl;
    cout << "5. To edit grade"<< endl; 
    cout << "6. To edit guardian's phone number"<< endl;
    cout << "7. To return to the mainmenu"<<endl<<endl;
    cout << "choice: "; cin>>option;

    system("cls");
    
    //Add user input validation!!!!!@@######@%@%%%%%%%%%%%%%%%%%%%%%%
    
    switch(option)
    {
        case 1:
        cout<<"Enter new ID: ";
        cin>>students[row-1].student_ID;
        break;

        case 2:
        cout<<"Enter new first name: ";
        cin>>students[row-1].first_name;
        break;

        case 3:
        cout<<"Enter new surname: ";
        cin>>students[row-1].surname;
        break;

        case 4:
        cout<<"Enter new age: ";
        cin>>students[row-1].age;
        break;

        case 5:
        cout<<"Enter new grade: ";
        cin>>students[row-1].grade;
        break;

        case 6:
        cout<<"Enter new guardian's phone number: ";
        cin>>students[row-1].guardians_phone_number;
        break;
    }

    return;
}


void retrieve_data()
{
    string h1, h2, h3, h4, h5, h6;

    ifstream outputfile("students.txt");
    if(outputfile)
    {
        outputfile>>h3>>h1>>h2>>h4>>h5>>h6;

        for(int row = 0; row < MAX_ROWS; row++)
        {
            outputfile>>students[row].student_ID>>students[row].first_name>>students[row].surname>>students[row].age>>students[row].grade>>students[row].guardians_phone_number;
        }   
    }
    else
    {
        cerr <<"file cannot open"<<endl;
        system("pause");
        exit(1);
    }
    outputfile.close();
}
