#pragma once
#include<iostream>
using namespace std;
#include<string>
class Admin
{
public:
    string email;
    string password;
    Admin();
    void Get_DataAdmin(); //take input of user id and password
    void Display_dataAdmin(); //display id and password of all users
};