#include<cstdio>
#include<cstdlib>
#include<fstream>
#include <ctime>
#include"Admin.h"
#include"Train.h"
#include"Book.h"
#include"Register.h"
#include"Time.h"
#include"ArrList.cpp"
using namespace std;

void first_menu();
void admin_secound_menu();
void passenger_secound_menu();
void AdminMode();
void PassengerMode();

void getDataAdmin();
void getdatatrain();
void getDataRegister();
void getDataBook();


void savetrain();
void saveRegister();
void saveAdmin();
void saveBook();


void SignUp_Admin();
void SignUp_Register();


void SignIn_Admin();
void SignIn_Register();

void AddTrain();
void ShowTrain();
void EditTrain();


void Add_ticket();
void update_ticket();
void show_ticket();



void giveBookToRegister();



vector<Train>Train_vector;
vector<Register>Register_vector;
vector<Admin>Admin_vector;
vector<Book>Book_vector;



void main()
{
	//get all data from file and store in vector 
	getDataRegister();
	getDataBook();
	getDataAdmin();
	getdatatrain();

	
	cout << "\t\t\t\t\t\t [ Railway Project ] \n\n\n\n\n\n";
	first_menu();
}

//void checkprogram()
//{
//	Register tmp;
//	Book b;
//	
//	for (int i = 0; i < regis.Length(); i++)
//	{
//		
//		tmp = regis.At(i);
//		b = book.At(i);
//		cout << tmp.email <<endl;
//		cout << tmp.ticket.size() << endl;
//		
//	}
//}*/

void first_menu()
{
	string first_Value;
	bool first_Wrong_Value = true;

	

	while (first_Wrong_Value)
	{



		cout << "Please enter\n\n ( 1 ) to Admin page   \n\n ( 2 ) to passenger page\n\n ( 3 ) to end program \n\n  value : ";
		cin >> first_Value;

		if (first_Value == "1")
		{
			system("cls");
			admin_secound_menu();

			first_Wrong_Value = false;

		}
		else if (first_Value == "2")
		{
			system("cls");
			passenger_secound_menu();
			first_Wrong_Value = false;
		}
		else if (first_Value == "3")
		{
			cout << "\t\t\t********************* (    Good bye    ) ********************** ";
			exit(0);
		}
		else
		{
			cout << " \n\n\n \t\t\t\t\t!!!! invalid value please try again !!!!\n\n\n\n";
		}


	}













}

void admin_secound_menu()
{
	string secound_Value;
	bool secound_Wrong_Value = true;



	while (secound_Wrong_Value)
	{



		cout << " \n \n Please enter\n\n ( 1 ) to sign up \n\n ( 2 ) to sign in \n\n ( 3 ) to return to first menu\n\n ( 4 ) to end program \n\n  value : ";
		cin >> secound_Value;

		if (secound_Value == "1")
		{

			SignUp_Admin();
			secound_Wrong_Value = false;
		}
		else if (secound_Value == "2")
		{
			SignIn_Admin();
			secound_Wrong_Value = false;
		}
		else if (secound_Value == "3")
		{
			first_menu();
			secound_Wrong_Value = false;
		}
		else if (secound_Value == "4")
		{
			exit(0);
			secound_Wrong_Value = false;
		}
		else
		{
			cout << " \n\n\n \t\t\t\t\t!!!! invalid value please try again !!!!\n\n\n\n";
		}




	}


}

void SignUp_Admin()
{
	Admin tmp;
	system("cls");
	tmp.Get_DataAdmin();
	Admin_vector.push_back(tmp);
	saveAdmin();
	cout << "\n\n\t\t\t\t ***********( \" # Successfully registered  # \" )*********\n\n\n\n";

	AdminMode();
}

void SignIn_Admin()
{

	Admin check_admin;
	string email;
	string pass;


	system("cls");

	cout << "enter your email : ";
	cin >> email;
	cout << endl << "enter your password :";
	cin >> pass;


	for (int i = 0; i < Admin_vector.size(); i++)
	{

		check_admin = Admin_vector.at(i);
		if (check_admin.email == email && check_admin.password == pass)
		{
			system("cls");
			AdminMode();
		}
		else if (i == Admin_vector.size() - 1)
		{

			int answer;
			bool check = true;
			system("cls");

			while (check)

			{

				cout << " \t\t\t************( Username or Password incorrect please try again )******************* " << endl << endl;
				cout << "please  enter\n\n" << "( 1 ) to try again" << endl << "( 2 ) to return to last menu \n\n" << " answer :";
				cin >> answer;


				if (answer == 1)
				{
					SignIn_Admin();
					check = false;
				}
				else if (answer == 2)
				{
					system("cls");
					admin_secound_menu();
					check = false;
				}
				else
				{
					cout << "***************( invalid data please try again )******************" << endl << endl;
				}
			}
		}

	}

}

void AdminMode()
{

	int choice;



	cout << "\t\t\t ************************* (    Admin Page   ) ************************\n\n\n\n\n\n\n";
	cout << " Please Enter\n\n";
	cout << "( 1 ) to Add Train " << endl << "( 2 ) to Edit Train" << endl << "( 3 ) to Show Train" << endl << "( 4 ) to sign out\n\n" << "Answer : ";
	cin >> choice;


	if (choice == 1)
	{
		system("cls");
		AddTrain();
	}
	else if (choice == 2)
	{
		system("cls");
		EditTrain();
	}
	else if (choice == 3)
	{
		system("cls");
		ShowTrain();
	}
	else if (choice == 4)
	{
		system("cls");
		first_menu();
	}
	else
	{

		cout << "  ****  Invalid Choice Please Choose a Valid number **** " << endl;
		AdminMode();
	}
}

void AddTrain()
{
	Train tmp;
	tmp.Get_dataTrain();
	Train_vector.push_back(tmp);
	savetrain();

}

void EditTrain()
{
	Train x;
	int EditNo;


	cout << "Enter the Number of the Train you want to Edit : ";
	cin >> EditNo;

	if (EditNo <= Train_vector.size() && EditNo >= 0)
	{
		Train_vector.erase(Train_vector.begin() + EditNo - 1);
		x.Get_dataTrain();
		Train_vector.insert(Train_vector.begin() + (EditNo - 1), x);

		savetrain();
		AdminMode();
	}
	else
	{
		int choice;
		cout << "\t\t\t************************ ( No train with this number try again ) ********************\n\n\n";
		cout << "please enter : \n\n\n";
		cout << "( 1 ) to return to admin page\n" << "( 2 ) to try edit train again\n\n" << " answer : ";
		cin >> choice;
		if (choice == 1)
		{
			AdminMode();
		}
		else if (choice == 2)
		{
			system("cls");
			EditTrain();
		}
		else
		{
			cout << "*****************************(  invalid data please try again ) ******************" << endl;
		}
		EditTrain();
	}
}

void ShowTrain()
{
	Train x;

	if (Train_vector.size() != 0)
	{
		for (int i = 0; i < Train_vector.size(); i++)
		{

			x = Train_vector.at(i);
			x.Display_dataTrain();
			cout << endl;

		}
		
	}
	else
	{
		cout << "\t\t\t\t********************* ( No train available ) ********************\n\n\n\n\n";
		
	}


}

void update_ticket()
{
	bool Check = false;
	Book tmp;
	int x;
	string email;
	
	cout << "enter your email : ";
	cin >> email;


	for (int i = 0; i < Book_vector.size(); i++)
	{
		
		if (email == Book_vector.at(i).email)
		{
			x = i;
			Check = true;
			break;
		}
	}
	Book_vector.erase(Book_vector.begin() + x);
	tmp.Get_dataBook();
	Book_vector.insert(Book_vector.begin() + (x), tmp);
	saveBook();
	for (int i = 0; i < Register_vector.size(); i++)
	{
		if (email == Register_vector.at(i).email)
		{
			Register_vector.at(i).Set_ticket(tmp);
			break;
		
		}
	}

	if (Check)
	{
		cout << "Update Successful" << endl;
		PassengerMode();
	}
	else
	{
		cout << "Update Unsuccessful" << endl;
		PassengerMode();
	}
}

void passenger_secound_menu()
{

	string secound_Value;
	bool secound_Wrong_Value = true;

	while (secound_Wrong_Value)
	{



		cout << " \n \n Please enter\n\n ( 1 ) to sign up \n\n ( 2 ) to sign in \n\n ( 3 ) to return to first menu \n\n ( 4 ) to end program \n\n  value : ";
		cin >> secound_Value;



		if (secound_Value == "1")
		{
			
			SignUp_Register();
		}
		else if (secound_Value == "2")
		{
			SignIn_Register();
			secound_Wrong_Value = false;
		}
		else if (secound_Value == "3")
		{
			first_menu();
			secound_Wrong_Value = false;
		}
		else if (secound_Value == "4")
		{
			exit(0);
			secound_Wrong_Value = false;
		}
		else
		{
			cout << " \n\n\n \t\t\t\t\t!!!! invalid value please try again !!!!\n\n\n\n";
		}



	}


}

void SignUp_Register()
{
	Register tmp;
	system("cls");
	tmp.Get_dataregister();
	Register_vector.push_back(tmp);
	saveRegister();
	cout << "\n\n\t\t\t\t ***********( \" # Successfully registered  # \" )*********\n\n\n\n";
	first_menu();
}

void SignIn_Register()
{

	Register check_regis;
	string email;
	string pass;

	system("cls");



	cout << "enter your email : ";
	cin >> email;
	cout << endl << "enter your password : ";
	cin >> pass;





	for (int i = 0; i < Register_vector.size(); i++)
	{
		check_regis = Register_vector.at(i);
		if (check_regis.email == email && check_regis.Password == pass)
		{
			system("cls");
			PassengerMode();

		}
		else if (i == Register_vector.size() - 1)
		{


			int answer;
			bool check = true;
			system("cls");



			while (check)
			{
				system("cls");

				cout << " \t\t\t************( Username or Password incorrect please try again )******************* " << endl << endl;
				cout << "please  enter\n\n" << "( 1 ) to try again" << endl << "( 2 ) to return to last menu \n\n" << " answer :";
				cin >> answer;


				if (answer == 1)
				{
					SignIn_Register();
					check = false;
				}
				else if (answer == 2)
				{
					system("cls");

					check = false;
					passenger_secound_menu();
				}

				else
				{
					cout << "***************( invalid data please try again )*************" << endl << endl;
				}


			}





		}

	}
}

void PassengerMode()
{
	system("cls");
	int choice;



	cout << "\t\t\t ************************* (    Passenger Page   ) ************************\n\n\n\n\n\n\n";
	cout << " Please Enter\n\n";
	cout << "( 1 ) to Add Ticket " << endl << "( 2 ) to Edit Ticket" << endl << "( 3 ) to Show your ticket\n\n" << "Answer : ";
	cin >> choice;

	if (choice == 1)
	{
		Add_ticket();

	}

	else if (choice == 2)
	{
		update_ticket();

	}
	else if (choice == 3)
	{

		show_ticket();
	}
	else
	{
		cout << "Invalid option";
		PassengerMode();
	}
}

void Add_ticket()
{
	Book tmp_Book;
	Train tmp_train;
	

	
	time_t currentTime = time(0);	 // Get the current time
	struct tm localTime;

	localtime_s(&localTime, &currentTime);  // Convert the current time to the local time

	int Day = localTime.tm_mday;
	int Month = localTime.tm_mon + 1;
	int Year = localTime.tm_year + 1900;
	int Hour = localTime.tm_hour;
	int Min = localTime.tm_min;
	int Sec = localTime.tm_sec;


		





	int* a = new int[Train_vector.size()];
	int counterAvailiable = 0;
	int choice;
	bool check = false;
	for (int i = 0; i < Train_vector.size(); i++)
	{
		a[i] = i;
	}

	tmp_Book.Get_dataBook();
	for (int i = 0; i < Train_vector.size(); i++)
	{
		tmp_train = Train_vector.at(i);
		if (tmp_Book.Boarding == tmp_train.board && tmp_Book.Destination == tmp_train.dest )
		{
			if (tmp_Book.Year>tmp_train.Year)
			{
				check = true;
				cout << "( " << (counterAvailiable + 1) << " )\n\n";
				tmp_train.Display_dataTrain();

				cout << "\n\n\n";

				counterAvailiable++;
			}
			else if (tmp_Book.Year == tmp_train.Year && tmp_Book.Month<tmp_train.Month)
			{
				check = true;
				cout << "( " << (counterAvailiable + 1) << " )\n\n";
				tmp_train.Display_dataTrain();

				cout << "\n\n\n";

				counterAvailiable++;
			}
			else if (tmp_Book.Year == tmp_train.Year && tmp_Book.Month == tmp_train.Month && tmp_Book.Day<tmp_train.Day)
			{
				check = true;
				cout << "( " << (counterAvailiable + 1) << " )\n\n";
				tmp_train.Display_dataTrain();

				cout << "\n\n\n";

				counterAvailiable++;
			}
			else if (tmp_Book.Year == tmp_train.Year && tmp_Book.Month == tmp_train.Month && tmp_Book.Day == tmp_train.Day )
			{
				check = true;
				cout << "( " << (counterAvailiable + 1) << " )\n\n";
				tmp_train.Display_dataTrain();

				cout << "\n\n\n";

				counterAvailiable++;
			}
			


		}


	}
	if (check)
	{

		cout << "\n\n which train do you want ? ";
		cin >> choice;

		tmp_train = Train_vector.at(a[choice - 1]);
		tmp_train.NumOfSeats--;

	}
	else

	{
		int choice;
		system("cls");

		cout << "\t\t\t*********************** (  no tickets availiable ) ****************************\n\n\n\n";
		cout << "Please Enter \n\n\n";
		cout << "( 1 ) to book Another ticket\n\n";
		cout << "( 2 ) return to last menu\n\n";
		cout << " answer : ";
		cin >> choice;


		bool enter = false;
		while (enter = false)
		{
			if (choice == 1)
			{
				enter = true;
				system("cls");
				Add_ticket();
			}
			else if (choice == 2)
			{
				enter = true;
				PassengerMode();
			}
			else
			{
				cout << "***********************(  wrong answer please try again ) ******************\n\n";
			}




		}
	}

	Book_vector.push_back(tmp_Book);

	saveBook();
	system("cls");
	PassengerMode();
}

void show_ticket()
{
	string email;

	cout << "enter your email : ";
	cin >> email;
	
	for (int i = 0; i < Register_vector.size(); i++)
	{
		
		if (email== Register_vector.at(i).email)
		{
			Register_vector.at(i).ticket.Display_dataBook();
		}
	}
}

void saveAdmin()
{
	Admin tmp;

	ofstream storageAdmin("Admin.txt");
	for (int i = 0; i < Admin_vector.size(); i++)
	{
		tmp = Admin_vector.at(i);
		storageAdmin << tmp.email << endl << tmp.password << endl;
	}
	storageAdmin.close();
}

void getDataAdmin()
{
	//cout << " get data train\n";

	ifstream storageAdmin("Admin.txt");

	//end file
	while (!storageAdmin.eof())
	{
		Admin new_Admin;
		string line;
		getline(storageAdmin, line);
		if (line != "")
			new_Admin.email = line;
		else
			break;
		getline(storageAdmin, new_Admin.password);

		//cout << "add to list\n";
		Admin_vector.push_back(new_Admin);
	}
	storageAdmin.close();
}

void saveRegister()
{
	Register tmp;

	ofstream storageRegister("Register.txt");
	for (int i = 0; i < Register_vector.size(); i++)
	{
		tmp = Register_vector.at(i);
		storageRegister << tmp.email << endl << tmp.Password << endl;
	}
	storageRegister.close();
}

void getDataRegister()
{
	//cout << " get data train\n";

	ifstream storageRegister("Register.txt");

	//end file
	while (!storageRegister.eof())
	{
		Register new_Admin;
		//cout << "rnter loob\n";
		string line;
		getline(storageRegister, line);
		if (line != "")
			new_Admin.email = line;
		else
			break;
		getline(storageRegister, new_Admin.Password);
	

		//cout << "add to list\n";
		Register_vector.push_back(new_Admin);
	}
	storageRegister.close();
}

void savetrain()
{
	Train tmp;

	ofstream storagetrain("Train.txt");
	for (int i = 0; i < Train_vector.size(); i++)
	{
		tmp = Train_vector.at(i);
		storagetrain << tmp.train_name << endl << tmp.train_num << endl << tmp.board << endl
			<< tmp.dest << endl << tmp.cost << endl << tmp.numofseat << endl
			<< tmp.day << endl << tmp.month << endl << tmp.year << endl << tmp.hour << endl << tmp.minute << endl;
	}
	storagetrain.close();
}

void getdatatrain()
{
	//cout << " get data train\n";
	Train nt;
	string line;
	ifstream storagetrain;
	storagetrain.open("Train.txt");
	//end file
	while (!storagetrain.eof())
	{

		getline(storagetrain, line);
		if (line == "")
			break;
		nt.train_name = line;
		getline(storagetrain, nt.train_num);
		getline(storagetrain, nt.board);
		getline(storagetrain, nt.dest);
		getline(storagetrain, nt.cost);
		getline(storagetrain, nt.numofseat);
		getline(storagetrain, nt.day);
		getline(storagetrain, nt.month);
		getline(storagetrain, nt.year);
		getline(storagetrain, nt.hour);
		getline(storagetrain, nt.minute);


		nt.Day = stoi(nt.day);
		nt.Month = stoi(nt.month);
		nt.Year = stoi(nt.year);
		nt.Hour = stoi(nt.hour);
		nt.Minute = stoi(nt.minute);
		nt.NumOfSeats = stoi(nt.numofseat);
		cout << "added to list\n";
		Train_vector.push_back(nt);
	}
	storagetrain.close();
}

void saveBook()
{
	Book tmp;
	ofstream storageBook("Book.txt");
	for (int i = 0; i < Book_vector.size(); i++)
	{
		tmp = Book_vector.at(i);

		storageBook <<tmp.email<<endl<< tmp.Passenger_name << endl<<tmp.Boarding<<endl<<
			tmp.Destination <<endl<< tmp.day << endl << tmp.month << endl << tmp.year << endl;
	}
	storageBook.close();

}

void getDataBook()
{
	   Book tmpbook;
	   string line;
		ifstream storageBook("Book.txt");
		
		
		while (!storageBook.eof())
		{
			getline(storageBook, line);
			if (line == "")
				break;
			//cout<< "found email\n";
			tmpbook.email = line;
			getline(storageBook, tmpbook.Passenger_name);
			getline(storageBook, tmpbook.Boarding);
			getline(storageBook, tmpbook.Destination);
			getline(storageBook,tmpbook.day );
			getline(storageBook, tmpbook.month);
			getline(storageBook, tmpbook.year);
			getline(storageBook, tmpbook.hour);
			getline(storageBook, tmpbook.minute);
			tmpbook.Day = stoi(tmpbook.day);
			tmpbook.Month = stoi(tmpbook.month);
			tmpbook.Year = stoi(tmpbook.year);
			
			Book_vector.push_back(tmpbook);
			//cout << "add to ds\n";
		}

		storageBook.close();
		giveBookToRegister();

}

void giveBookToRegister()
{
	
	for (int i = 0; i < Register_vector.size(); i++)
	{
		

		for (int j = 0; j < Book_vector.size(); j++)
		{
			 
			if (Register_vector.at(i).email == Book_vector.at(j).email)
			{
				//cout << Register_vector.at(i).email << "    " << Book_vector.at(j).email << endl;
				Register_vector.at(i).Set_ticket(Book_vector.at(j));
			}
		}
	}
}