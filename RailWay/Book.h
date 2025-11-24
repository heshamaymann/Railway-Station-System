#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book
{
public:
    string email;
    string Passenger_name; //Passenger Name
    string Boarding;         //Boarding Station
    string Destination;      //Destination Station
    string day, month, year, hour, minute;     //Day Month Year 
    int Day, Month, Year, Hour, Minute;
    Book();
    void Get_dataBook(); //Get passenger Details
    void Display_dataBook(); //Display
    void stoibook();
};

