#include "Register.h"


Register::Register()
{
    
}

void Register::Set_ticket(Book value)
{
   // cout << value.Passenger_name << endl;
    ticket = value;
}

void Register::Get_dataregister()
{
    cout << "\nEnter the details as follows\n";
    cout << "your email:";
    cin >> email;
    cout << "your pass:";
    cin >> Password;
}

void Register::Display_Dataregister()
{
    cout << "your username is : " << email << endl;
    cout<< "your password is :" << Password << endl;
    cout << "\n \n \n \n";
}


