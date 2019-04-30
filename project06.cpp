/*
Mini project: Flight Booking
18121A1226
18121A1224
18121A1256
18121A1258
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include<time.h>
using namespace std;

class BOOKING
{
 public :
 char name[20];
 char add[50];
 char email[50];
 long mobile;
 int age;
 char sex;
 char departure[25];
 char arrival[25];
 char date[10];
 long long aadhar;
 public :
 int getInfo()
 {
 cout << "Enter Passenger's Name :- ";
 cin.get();
 cin.getline(name,20);

 cout << "Enter the Address Details :- ";
 cin.getline(add,50);

 cout << "Enter your email address :- ";
 cin.getline(email,50);

 cout << "Enter your Phone Number :- ";
 cin >> mobile;

 cout << "Enter your Age :- ";
 cin >> age;

 cout <<"Enter Sex(M/F) :- ";
 cin >> sex;

 cout << "Enter Aadhar Number :- ";
 cin >> aadhar;

 int n;
 int k = 0;
 do
 {
 cout << "\n\t\tSelect Your City of Departure\n";
 cout << "\t\t-----------------------------\n";
	cout << "\t1. Patna\n";
	cout << "\t2. Goa\n";
	cout << "\t3. Bengaluru\n";
	cout << "\t4. New Delhi\n";
	cout << "\t5. Mumbai\n";
	cout << "Please Input Your Choice Number :- ";
 cin >> n;
	switch (n)
 {
 case 1:
 strcpy(departure, "PATNA");
 break;
 case 2:
 strcpy(departure, "Goa");
 break;
 case 3:
 strcpy(departure, "BENGALURU");
 break;
 case 4:
 strcpy(departure, "NEW DELHI");
 break;
 case 5:
 strcpy(departure, "MUMBAI");
 break;
 default:
 cout << "Invalid Choice . Please Try Again.\n";
 k++;
	}
 }while(k != 0);

 int p = 0;
 do
 {
 switch(n)
 {
 case 1:
 strcpy(arrival,"NEW DELHI");
 break;
 case 2:
 strcpy(arrival,"PATNA");
 break;
 case 3:
 strcpy(arrival,"MUMBAI");
 break;
 case 4:
 strcpy(arrival,"BENGALURU");
 break;
 case 5:
 strcpy(arrival,"CHENNAI");
 break;
 default:
 cout << "Invalid choice . Please Try Again.\n";
 p++;
 }
 }while(p != 0);

 }

 int disInfo()
 {
 cout.setf(ios::left);
 cout <<setw(15)<< name  <<setw(15)<< mobile <<setw(12)<< departure <<setw(12)<< arrival<<endl;
 }

};
class FLIGHTS
{
 char flight_name[10];
 char flight_carrier[20];
 char time_depart[10];
 char time_arrival[10];

 public :
 int flightInfo()
 {
 //cout << "Enter the Flight Name :- ";//
 }
};

int main()
{
start :
 cout << "*********************************************************************\n";
 cout <<"..............Welcome to the CADBURY Airline Services ............\n";
 cout << "*********************************************************************\n";
 int k = 0;
 int choice;
 int fare;
 do
 {
 cout <<"click option of your choice"<<endl;
 cout << "--------------------------------------------------------------------\n";
 cout << "\t1. Booking\n";
 cout << "\t2. Flight Details\n";
 cout << "\t3. Fare details\n";
 cout << "\t4. Passenger Details\n";


 cout << "Please Enter your Preferred Choice :- ";
 cin >> choice;
 if(choice<1 || choice >4)
 {
 cout << "\nInvalid Choice . Please Try Again .\n";
 k++;
 }
 }while (k != 0);

 switch (choice)
 {
 case 1:
 {
 BOOKING b;
 fstream f1;
 char ch;
 int FNO;
 int book_id = 1;
 f1.open("booking.txt",ios::in|ios::out|ios::app|ios::binary);
 cout << "\t\tWelcome to Booking Services\n";
 cout << "\t\t---------------------------\n";

 do
 {
 int CNO,fare;	
 b.getInfo();
 f1.write((char *)&b , sizeof(b));

 cout << "\n\t\tBooking Details are following\n";
 cout << "\t\t-----------------------------\n";
 cout.setf(ios::left);
 cout <<setw(15)<<"Name   "<<setw(15)<<"Mobile         "<<setw(12)<<"Depart       "<<setw(12)<<"Arrival      "<<endl;
 cout <<"----------------------------------------------------------------------------------------------------"<<endl;
 cout <<setw(15)<<"       "<<setw(15)<<"               "<<setw(12)<<"             "<<setw(12)<<"             "<<endl;
 b.disInfo();
 cout<<"enter flight number "<<endl;
 cin>>FNO;
 {
 if(FNO==1101)
  cout<< " Total Fare is Rs.5500" <<fare<<endl;
 else if(FNO==1102)
  cout<< "Total Fare is Rs.6000" <<fare<<endl;
 else if(FNO==1103)
  cout<<"Total Fare is Rs.8000" <<fare<<endl;
 else if(FNO==1104)
  cout<<" Total Fare is Rs.10000" <<fare<<endl;
 else if(FNO==1105)
  cout<<"Total Fare is  Rs.12000" <<fare<<endl;
}
 cout << "\nDo you want to register again ?\n";
 cout << "(Y for yes,N for no)";
 cin >> ch;
 }while (ch == 'Y'|| ch == 'y');
 cout << "\n\t..........Booking Successful...............\n";

 char c1;
 cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
 cin >>c1;
 if(c1 == 'q' || c1 == 'Q')
 exit(EXIT_FAILURE);
 else
 goto start;
 f1.close();
 }
 break;

 case 2:
 {
 FLIGHTS f;
 fstream f2;
 f2.open("flights.txt",ios::in|ios::out|ios::app);
 char ch = 'Y';
 while (ch == 'Y'||ch == 'y')
 {
 f.flightInfo();
 f2.write((char *)&f,sizeof(f));
 cout<<"List of flights available:"<<endl;
 cout<<"Flight number   "<<"Flight name 	"<<" From       	  "<<" To 	       "<<" Departure Time	 "<<endl;
 cout<<"-------------------------------------------------------------------------------------------------"<<endl;
 cout<<"1101.           "<<"Spicejet        "<<" Patna            "<<" New dehi    "<<"    12:00pm       "<<endl;
 cout<<"1102.           "<<"Kingfisher      "<<" Goa              "<<" Patna       "<<"    5:30pm        "<<endl;
 cout<<"1103.           "<<"AirIndia        "<<" Banglore         "<<" Mumbai      "<<"    2:45am        "<<endl;
 cout<<"1104.           "<<"Jetlines        "<<" New delhi        "<<" Banglore    "<<"    7:30pm        "<<endl;
 cout<<"1105.           "<<"Emirates        "<<" Mumbai           "<<" Chennai     "<<"    9:30am        "<<endl;
 char c2;
 cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
 cin >>c2;
 if(c2 == 'q' || c2 == 'Q')
 exit(EXIT_FAILURE);
 else
 goto start;
 f2.close();
 
 }
 }
 case 3:
 {
 int FNO;	
  cout<<"enter the flight number"<<FNO<<endl;
  cin>>FNO;
  if(FNO==1101)
  {
  	cout<<"1101.SPICEJET from patna to newdelhi at 12:00pm"<<endl;
  	cout<<"total fare is Rs.5500 per ticket";
  }
  else if(FNO==1102)
  {
  	cout<<"KINGFISHER from goa to Patna at 5:30pm"<<endl;
  	cout<<"total fare is Rs.6000 per ticket";
  }
  else if(FNO==1103)
  {
  	cout<<"1103.AIRINDIA from Banglore to Mumbai at 2:45am"<<endl;
  	cout<<"total fare is Rs.8000 per ticket";
  }
  else if(FNO==1104)
  {
  	cout<<"1104.JETLINES from delhi to Banglore at 7:30pm"<<endl;
  	cout<<"total fare is Rs.10000 per ticket";
  }
  else if(FNO==1105)
  {
  	cout<<"1105.EMIRATES from Mumbai to Chennai at 9:30am"<<endl;
  	cout<<"total fare is Rs.12000 per ticket";
  }
  char c3;
 cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
 cin >>c3;
 if(c3 == 'q' || c3 == 'Q')
 exit(EXIT_FAILURE);
 else
 goto start;
}
 case 4:
 {
 BOOKING p;
 int count = 0;
 fstream f6;
 f6.open("booking.txt");
 f6.seekg(0,ios::beg);
 f6.read ((char *)&p,sizeof(p));
 cout.setf(ios::left);
 cout <<endl;
 cout <<setw(15)<<"Name   "<<setw(15)<<"Mobile         "<<setw(12)<<"Depart       "<<setw(12)<<"Arrival      "<<endl;
 cout <<setw(15)<<"       "<<setw(15)<<"               "<<setw(12)<<"             "<<setw(12)<<"             "<<endl;
 while(f6.eof() != 1)
 {
 p.disInfo();
 f6.read ((char *)&p,sizeof(p));
 count++;
 }
 f6.close();
 cout << "\n\tTotal Number of passengers is "<<count<<endl;
 char c6;
 cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
 cin >> c6;

 if(c6 == 'q'|| c6 == 'Q')
 exit(EXIT_FAILURE);
 else
 goto start;
 }
 }
}
