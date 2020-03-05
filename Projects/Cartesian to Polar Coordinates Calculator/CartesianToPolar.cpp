#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double Polar();

int main()
{
	Polar();
	return 0;
}

double Polar()
{
	double x=0.0;
	double y=0.0;
	double r=0.0;
	double theta=0.0;
	
	cout<<"Enter x and y values\n";
	cin>>x>>y;
	
	r = sqrt((pow(x,2))+(pow(y,2)));
	theta = atan2(y,x) * 180.0 / M_PI;
	
	if (theta < 0)
	theta = theta + 360.0;
	
	cout << "The polar coordinates are: (" << r << "," << theta << ")" << endl;
	cout << "Distance from origin: " << r << endl;
	cout << "Angle (in radians) from x-axis: " << theta << endl;
	
	return 0;

}
