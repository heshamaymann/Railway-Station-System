#pragma once

#include<iostream>
#include<string>
using namespace std;
class Train
{
public:
    string train_name;                          //Train Name
    string train_num;                           //Train Number
    string board;                               //Boarding Station
    string dest;                                //Destination Station
    string cost;                                //Ticket Price
    string numofseat;                           //Train Capacity
    int NumOfSeats;
    string day, month, year, hour, minute;      //Day Month Year
    int Hour, Minute;
    int Day, Month, Year;
    Train();
    void Get_dataTrain(); //Get Train Information from admin
    void Display_dataTrain(); //Display Train detail
    void setnumseats(int);
};
