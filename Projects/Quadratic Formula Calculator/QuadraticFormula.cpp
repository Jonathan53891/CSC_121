#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

string quadratic(double a,double b,double c);
double ReadDouble(string prompt);
double a=0.0;
double b=0.0;
double c=0.0;
double PositiveQuadratic=0.0;
double NegativeQuadratic=0.0;
double choice=0.0;

int main()
{
	double choice=0.0;	
	while(choice !=2)
	{
		a = ReadDouble("Choose a value for a\n");
		b = ReadDouble("Choose a value for b\n");
		c = ReadDouble("Choose a value for c\n");
		
		quadratic(a, b, c);
		cout<<"Please input necessary values to continue quadratic program.\n";
		cout<<"Choose one of the following choices:\n";
		cout<<"1. Compute Quadratic Formula\n";
		cout<<"2. Quit Program\n";

		cin>>choice;
	}
	
	return 0;
}

string quadratic(double a,double b,double c)
{
	while(pow(b,2)<(4*a*c))
	{
		cout<<"Please enter values such that b^2 will be greater than 4*a*c\n";
		a = ReadDouble("Choose a value for a\n");
		b = ReadDouble("Choose a value for b\n");
		c = ReadDouble("Choose a value for c\n");
	}
	PositiveQuadratic = ((-1*b)+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	NegativeQuadratic = ((-1*b)-sqrt(pow(b,2)-(4*a*c)))/(2*a);
	cout<<"Final output of the requested quadratic\n";
	cout<<"x = "<<PositiveQuadratic<<" or "<<NegativeQuadratic<<endl;
}

double ReadDouble(string prompt)
{
	string input;
	double retVal;
	int count = 0;
	cout << prompt;
	cin >> input;
	for(int i=0;i<input.length();i++){
		if (input[i] == '.'|| count > 0){
			count++;
		}
		while(isalpha(input[i]) !=0 || count > 2){
			cout<<"Quadratic cannot have multiple decimal points and only accepts number values.\n";
			cout << prompt;
			cin >> input;
			i = -1;
			count = 0;
		}
	}
	return retVal = atof(input.c_str());
}
