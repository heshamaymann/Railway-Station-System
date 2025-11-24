#include "Train.h"

Train::Train()
{

}


void Train::Get_dataTrain()
{
    system("cls");
    cout << "Enter the details as follows\n\n\n";
    cout << " Train no : ";
    cin >> train_num;
    cout << " \n\nTrain name : ";
    cin >> train_name;
    cout << " \n\nBoarding point : ";
    cin >> board;
    cout << "\n\nDestination point : ";
    cin >> dest;
    cout << "\n\ncost : ";
    cin >> cost;
    cout << "\n\nnumofseat : ";
    cin >> numofseat;
    cout << "\nDay : ";
    cin >> day;
    cout << "\nMonth : ";
    cin >> month;
    cout << "\nYear : ";
    cin >> year;
    cout << "\nHour: ";
    cin >> hour;
    cout << "\nMinute: ";
    cin >> minute;
    Day = stoi(day);
    Month = stoi(month);
    Year = stoi(year);
    Hour = stoi(hour);
    Minute = stoi(minute);
    NumOfSeats = stoi(numofseat);
}
void Train::Display_dataTrain()
{
    cout << train_num << endl << train_name << endl << board << endl << dest << endl;
    cout << cost << endl << day << "-" << month << "-" << year << "\t" << endl << hour << ":" << minute << endl;
}

void Train::setnumseats(int val)
{
    numofseat = val;
}
