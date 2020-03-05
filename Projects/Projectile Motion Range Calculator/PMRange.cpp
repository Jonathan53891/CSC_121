#include <iostream>
#include <cmath>
const double g=32;
using namespace std;

int main()
{
	double vi=0.0;
	double angD=0.0;
	double feet=0.0;
	cout<<"Enter angle and velocity\n";
	cin>>angD>>vi;
	double angR=M_PI/180.0*angD;
	double v=vi*(5280.0/3600.0);
	double r=(v*v/32.0)*sin(2.0*angR);
	cout<<"Range in feet:"<<r<<endl;
	return 0;
}
