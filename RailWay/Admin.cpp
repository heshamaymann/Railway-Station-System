#include "Admin.h"



Admin::Admin()
{

}
void Admin::Get_DataAdmin()
{
	cout << "\n\nEnter your username : ";
	cin >> email;
	cout << "\nEnter your password : ";
	cin >> password;



}
void Admin::Display_dataAdmin()
{
	cout << " \n\n\n \t\t\t\tyour username is : " << email << endl << " \t\t\t\tyour password is :" << password << endl;
}