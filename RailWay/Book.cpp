#include "Book.h"


Book::Book()
{

}

void Book::Get_dataBook()
{
    system("cls");
    cout << "\n Enter the details as follows\n\n\n";
    cout << "\n\n email :";
    cin >> email;
    cout << "passenger name : ";
    cin >> Passenger_name;
    cout << "\n\nBoarding point : ";
    cin >> Boarding;
    cout << "\n\nDestination point : ";
    cin >> Destination;
    cout << "\n\nday : ";
    cin >> day;
    cout << "\n\nMonth : ";
    cin >> month;
    cout << "\n\nYear : ";
    cin >> year;

    Day = stoi(day);
    Month = stoi(month);
    Year = stoi(year);
    

    cout << "\n\n\n\t\t\t............END OF GETTING DETAILS............\n";

}



void Book::Display_dataBook()
{
    cout << "Passenger Name:";
    cout << Passenger_name;
    cout << "\n\nemail :";
    cout << email;
    cout << "\n\nBoarding Point: ";
    cout << Boarding;
    cout << "\n\nDestination Point: ";
    cout << Destination;
    

    cout << "\n\nDate of reservation: " << day << "-" << month << "-" << year<<endl;
    cout << "***********************************************\n";
    cout << "***********************************************\n\n";
}
void Book::stoibook()
{
    Day = stoi(day);
    Month = stoi(month);
    Year = stoi(year);
    Hour = stoi(hour);
    Minute = stoi(minute);


}