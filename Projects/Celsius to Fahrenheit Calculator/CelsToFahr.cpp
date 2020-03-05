#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double celsius=0.0;
	
	cout<<"Enter a temperature in degrees Celsius\n";
	cin>>celsius;
	
	double fahrenheit=((9.0/5.0)*celsius + 32.0);
	
	cout<<"Degrees in Fahrenheit:"<<fahrenheit<<endl;
	
	return 0;
}
