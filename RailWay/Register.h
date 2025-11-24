#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Book.h"
using namespace std;

class Register
{
public:
    string email;
    string Password;


    Book ticket;
    Register();
    void Get_dataregister();
    void Set_ticket(Book);
    void Display_Dataregister();
};
