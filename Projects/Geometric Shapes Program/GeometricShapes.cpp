#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Cube();
void Sphere();
void Prism();
void Cylinder();
void Cone();

double CubeArea(double side);
double CubeVolume(double side);
double SphereArea(double radius);
double SphereVolume(double radius);
double PrismArea(double length, double width,double height);
double PrismVolume(double length,double width,double height);
double CylinderArea(double radius,double length);
double CylinderVolume(double radius,double length);
double ConeArea(double radius,double height);
double ConeVolume(double radius,double height);

double choice=0.0;
double ReadDouble(string prompt);
void Area(double x);
void Volume(double x);

double length=0.0;
double width=0.0;
double height=0.0;

int main()
{
	cout<<"Choose one of the following choices:\n";
	cout<<"1. Cube\n";
	cout<<"2. Sphere\n";
	cout<<"3. Prism\n";
	cout<<"4. Cylinder\n";
	cout<<"5. Cone\n";
	cout<<"6. Quit\n";
	
	int choice;
        cin>>choice;
	
	while(choice !=6)
	{
		if(choice==1)
		{
			Cube();
		}
		
		if(choice==2)
		{
			Sphere();
		}
		
		if(choice==3)
		{
			Prism();
		}
		
		if(choice==4)
		{
			Cylinder();
		}
		
		if(choice==5)
		{
			Cone();
		}
		
		if(choice > 6 || choice < 1)
		{
			cout<<"Choice must be a value shown on the menu\n";
		}
	
	cout<<"Choose one of the following choices:\n";
	cout<<"1. Cube\n";
	cout<<"2. Sphere\n";
	cout<<"3. Prism\n";
	cout<<"4. Cylinder\n";
	cout<<"5. Cone\n";
	cout<<"6. Quit\n";
	
	cin>>choice;
		
	}
	
	cout<<"Shapes program has ended.\n";
	
	return 0;

}

void Cube()
{
	double side=ReadDouble("Enter side (m):");
	Area(CubeArea(side));
	Volume(CubeVolume(side));
}

double CubeArea(double side)
{
	double retVal=6*pow(side,2.0);
	return retVal;
}

double CubeVolume(double side)
{
	double retVal=pow(side,3.0);
	return retVal;
}

void Sphere()
{
	double radius=ReadDouble("Enter radius (m):");
	Area(SphereArea(radius));
	Volume(SphereVolume(radius));
}

double SphereArea(double radius)
{
	double retVal=M_PI*4.0*pow(radius,2.0);
	return retVal;
}

double SphereVolume(double radius)
{
	double retVal=M_PI*4.0*pow(radius,3.0)/3.0;
	return retVal;
}

void Prism()
{
	double length=ReadDouble("Enter length (m):");
	double width=ReadDouble("Enter width (m):");
	double height=ReadDouble("Enter height (m):");
	Area(PrismArea(length,width,height));
	Volume(PrismVolume(length,width,height));
}

double PrismArea(double length,double width,double height)
{
	double retVal=2.0*((width*length)+(height*length)+(height*width));
	return retVal;
}

double PrismVolume(double length,double width,double height)
{
	double volume=length*width*height;
	return volume;
}

void Cylinder()
{
	double radius=ReadDouble("Enter radius (m):");
	double height=ReadDouble("Enter height (m):");
	Area(CylinderArea(radius,height));
	Volume(CylinderVolume(radius,height));
}

double CylinderArea(double radius,double height)
{
	double retVal=(2.0*M_PI*radius*height)+(2.0*M_PI*pow(radius,2.0));
	return retVal;
}

double CylinderVolume(double radius,double height)
{
	double retVal=M_PI*height*pow(radius,2.0);
	return retVal;
}

void Cone()
{
	double radius=ReadDouble("Enter radius (m):");
	double height=ReadDouble("Enter height (m):");
	Area(ConeArea(radius,height));
	Volume(ConeVolume(radius,height));
}

double ConeArea(double radius,double height)
{
	double retVal=M_PI*radius*(radius+sqrt(pow(height,2.0)+pow(radius,2.0)));
	return retVal;
	
}

double ConeVolume(double radius,double height)
{
	double retVal=M_PI*height*pow(radius,2.0)/3.0;
	return retVal;
}

double ReadDouble(string prompt)
{
	double retVal=0.0;
	cout<<prompt;
	cin>>retVal;
	while(cin.fail() !=0 || retVal<0)
	{
		cin.clear();
		cin.ignore(255,'\n');
		cerr<<"Please choose a positive number as seen on the menu\n";
		cout<<prompt;
		cin>>retVal;
	}
	return retVal;
}

void Volume(double x)
{
	cout.width(8);
	cout.precision(4);
	cout<<"Volume:"<<x<<'\n'<<endl;
}

void Area(double x)
{
	cout.width(8);
	cout.precision(4);
	cout<<"Area:"<<x<<'\n'<<endl;
}
