#include <iostream>
#include <cmath>
using namespace std;
const double g=32;

int main()
{
	double vi=0.0;
	double angD=0.0;
	cout<<"Enter angle and velocity\n";
	cin>>angD>>vi;
	
	double angR=M_PI/180.0*angD;
	double v=vi*(5280.0/3600.0);
	double r=(v*v/g)*sin(2.0*angR);
	double t=r/v*cos(angR);
	double h=(v*sin(angR)*t/2.0)-(0.5*g*pow(t/2.0,2.0));
	double x=v*cos(angR)*t;
	double y=(v*sin(angR)*t)-(0.5*g*pow(t,2.0));
	cout<<"Range:"<<r<<endl;
	cout<<"Total Time:"<<t<<endl;
	cout<<"Max Height:"<<h<<endl;
	//cout<<"Distance in the x-direction:"<<x<<endl;
	//cout<<"Distance in the y-direction:"<<y<<endl;
	
	double sec=0.0;
	double increment=t/20.0;
	
	while(sec<t)
	{
		x=v*cos(angR)*sec;
		y=(v*sin(angR)*sec)-(0.5*g*pow(sec,2.0));
		t=r/v*cos(angR);
		cout<<"Current Time: "<<sec<<"\t"<<"X distance: "<<x<<"\t"<<"Y distance: "<<y<<"\t"<<endl;
		sec=sec+increment;

	}
	return 0;
}
