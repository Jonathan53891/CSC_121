#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double h1=0.0;
	double h2=0.0;
	cout<<"Enter height 1 and height 2\n";
	cin>>h1>>h2;
	double v=sqrt(2*9.8*(h1-h2));
	cout<<"velocity in meters per second:"<<v<<endl;
	return 0;
}
