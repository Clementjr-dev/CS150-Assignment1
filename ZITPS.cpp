#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int showmenu();
int login();

int main ()
{
    int option;

    if(login==true&&loginAsAd==true)
    {
        showmenu();
        option = showmenu();
    }



    return 0;
}

int login()
{
    static bool loginAsAd, login;
    int password, password1, password2, password3, password4;
    cout<<"Enter Password: ";
    cin>>password;

    ifstream credential;
    credential.open("credentials.txt");

    while(credential>>password1>>password2>>password3>>password4)

    if(password==password1||password==password2)
    {
        loginAsAd=true;
    }

    else if(password==password3||password4)
    {
        login=true
    }

    else
    {
        cout<<"Access Denied!\n";
        login=false;
        loginAsAd=false;
        login();
    }

}

int showmenu()
{
    int opt;

    cout<<"Main Menu\n";
    cout<<"Press: \n";
    cout<<"1. To add new pupil\n";
    cout<<"2. To delete pupil\n";
    cout<<"3. To search for pupil\n";
    cout<<"4. To edit pupil record\n";
    cout<<"5. To display all pupils by grade\n";
    cout<<"6. To exit\n";
    cin>>opt;
    if(opt>6||opt<1)
    {
        cout<<"Invalid option\n";
        showmenu();
    }

    return opt;
}
