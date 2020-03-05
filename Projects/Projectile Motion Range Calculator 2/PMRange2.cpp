#include <iostream>
#include <cmath>

using namespace std;         

void display_menu(); 
int get_menu_choice();
void angle_and_mph(int &angD, int &v);
void angle_and_kph(int &angD, int &vi);
double RangeMiles(int angD, int v);
double RangeKilometers(int angD, int vi);

int main()
{
	int choice;
		do
		{
			display_menu();
			choice=get_menu_choice();
			int x, y;
			double range_miles=0.0;
			double range_kilometers=0.0;
			int vi=0.0;
			int angD=0.0;
			double angR=M_PI/180.0*angD;
			double v=vi*(5280.0/3600.0);
			
			switch(choice)
			{
				case 1:
				{
					angle_and_mph(x,y);
					range_miles = RangeMiles(x,y);
					cout << "Range in miles: " << range_miles << endl;
					break;
				}
				case 2:
				{
					angle_and_kph(x, y);
					range_kilometers = RangeKilometers(x,y);
					cout << "Range in kilometers: " << range_kilometers << endl;
					break;
				}
			}
			
		}
	
		
		while(choice !=3);
		
		cout << "Thanks for particpating in my range calculation program. See you around!" << endl;
		
		return 0;
}

void display_menu()
{
	cout<<"If you would like to calculate the range in feet, type 1.\n"
	   <<"If you would like to calculate the range in meters, type 2.\n"
	   <<"If you would like to quit the range program, type 3.\n";
}

int get_menu_choice()
{
	int choice;
	cout << "Enter your selection (1, 2, or 3): ";
	cin >> choice;

	while(((choice < 1) || (choice > 3)) && (!cin.fail()))
	{
		cout << "Try again (1, 2, or 3): ";
		cin >> choice;
	}

	if (cin.fail())
	{
		cout << "Try again (1, 2, or 3): ";
		exit(1);
	}
	
	return choice;
}

void angle_and_mph(int &angD, int &v)
{
	cout << "Enter angle (in degrees) and velocity (in miles per hour): ";
	cin >> angD >> v;
}

void angle_and_kph(int &angD, int &vi)
{
	cout << "Enter angle (in degrees) and velocity (in kilometers per hour): ";
	cin >> angD >> vi;
}

double RangeMiles(int angD, int v)
{
	double angR=M_PI/180.0*angD;
	return ((v*v)/32.0)*sin(2.0*angR);
}

double RangeKilometers(int angD, int vi)
{
	double angR=M_PI/180.0*angD;
	return (vi*vi/9.8)*sin(2.0*angR);
}
