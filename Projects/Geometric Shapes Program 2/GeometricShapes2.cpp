#include <iostream>
#include <string>
#include <cmath>

#ifndef MEASURE_H
#define MEASURE_H

using namespace std;

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

void display_menu(); 
int get_menu_choice();

class Cube
{
	private:
		double side;
	public:
		void SetSide()
		{
			side = ReadDouble("Enter side (m):");
			while (side < 0)
			{
				cerr << "Side value cannot be negative." << endl;
				side = ReadDouble("Enter side (m):");
			}
		}
		
		double GetSide() {return side;}
		double CubeVolume() {return pow(side,3.0);}
		double CubeArea() {return 6*pow(side,2.0);}
};

class Sphere
{
	private:
		double radius;
		
	public:
		void SetRadius()
		{
			radius = ReadDouble("Enter radius (m):");
			while (radius < 0)
			{
				cerr << "Radius value cannot be negative." << endl;
				radius = ReadDouble("Enter radius (m):");
			}
		}
		
		double GetRadius() {return radius;}
		double SphereVolume() {return M_PI*4.0*pow(radius,3.0)/3.0;}
		double SphereArea() {return M_PI*4.0*pow(radius,2.0);}
};

class Prism
{
	private:
		double length;
		double width;
		double height;
		
	public:
		void SetLength()
		{
			length = ReadDouble("Enter length (m):");
			while (length < 0)
			{
				cerr << "Length value cannot be negative." << endl;
				length = ReadDouble("Enter length (m):");
			}
		}
		
		void SetWidth()
		{
			width = ReadDouble("Enter width (m):");
			while (width < 0)
			{
				cerr << "Width value cannot be negative." << endl;
				width = ReadDouble("Enter width (m):");
			}
		}
		
		void SetHeight()
		{
			height = ReadDouble("Enter height (m):");
			while (height < 0)
			{
				cerr << "Height value cannot be negative." << endl;
				height = ReadDouble("Enter height (m):");
			}
		}
		
		double GetLength() {return length;}
		double GetWidth() {return width;}
		double GetHeight() {return height;}
		double PrismVolume() {return length*width*height;}
		double PrismArea() {return 2.0*((width*length)+(height*length)+(height*width));}
};

class Cylinder
{
	private:
		double radius;
		double length;
		
	public:
		void SetRadius()
		{
			radius = ReadDouble("Enter radius (m):");
			while (radius < 0)
			{
				cerr << "Radius value cannot be negative." << endl;
				radius = ReadDouble("Enter radius (m):");
			}
		}
		
		void SetLength()
		{
			length = ReadDouble("Enter length (m):");
			while (length < 0)
			{
				cerr << "Length value cannot be negative." << endl;
				length = ReadDouble("Enter length (m):");
			}
		}
		
		double GetRadius() {return radius;}
		double GetLength() {return length;}
		double CylinderVolume() {return M_PI*length*pow(radius,2.0);}
		double CylinderArea() {return (2.0*M_PI*radius*length)+(2.0*M_PI*pow(radius,2.0));}
};

class Cone
{
	private:
		double radius;
		double height;
		
	public:
		void SetRadius()
		{
			radius = ReadDouble("Enter radius (m):");
			while (radius < 0)
			{
				cerr << "Radius value cannot be negative." << endl;
				radius = ReadDouble("Enter radius (m):");
			}
		}
		
		void SetHeight()
		{
			height = ReadDouble("Enter height (m):");
			while (height < 0)
			{
				cerr << "Height value cannot be negative." << endl;
				height = ReadDouble("Enter height (m):");
			}
		}
		
		double GetRadius() {return radius;}
		double GetHeight() {return height;}
		double ConeVolume() {return M_PI*height*pow(radius,2.0)/3.0;}
		double ConeArea() {return M_PI*radius*(radius+sqrt(pow(height,2.0)+pow(radius,2.0)));}
};

#endif

int main()
{
	
	int choice=0.0;
		
		do
		{
			display_menu();
			choice=get_menu_choice();
			
			switch(choice)
			{
				case 1://Cube
					Cube Cube;
					Cube.SetSide();
					cout << "Volume: " << Cube.CubeVolume() << endl;
					cout << "Area: " << Cube.CubeArea() << endl;
					break;
			
				case 2://Sphere
					Sphere Sphere;
					Sphere.SetRadius();
					cout << "Volume: " << Sphere.SphereVolume() << endl;
					cout << "Area: " << Sphere.SphereArea() << endl;
					break;
			
				case 3://Prism
					Prism Prism;
					Prism.SetLength();
					Prism.SetWidth();
					Prism.SetHeight();
					cout << "Volume: " << Prism.PrismVolume() << endl;
					cout << "Area: " << Prism.PrismArea() << endl;
					break;
		
				case 4://Cylinder
					Cylinder Cylinder;
					Cylinder.SetRadius();
					Cylinder.SetLength();
					cout << "Volume: " << Cylinder.CylinderVolume() << endl;
					cout << "Area: " << Cylinder.CylinderArea() << endl;
					break;
		
				case 5://Cone
					Cone Cone;
					Cone.SetRadius();
					Cone.SetHeight();
					cout << "Volume: " << Cone.ConeVolume() << endl;
					cout << "Area: " << Cone.ConeArea() << endl;
					break;
			
		
				case 6://Quit
		
				cout << "Thanks for particpating in my shapes program. See you around!" << endl;
		
				return 0;
			}
	
		}
	
		while(choice !=6);
		
		cout << "Thanks for particpating in my range calculation program. See you around!" << endl;
		
		return 0;
}

void display_menu()
{
	cout<<"Choose one of the following choices:\n";
		cout<<"1. Cube\n";
		cout<<"2. Sphere\n";
		cout<<"3. Prism\n";
		cout<<"4. Cylinder\n";
		cout<<"5. Cone\n";
		cout<<"6. Quit\n";
}

int get_menu_choice()
{
	int choice;
	cout << "Choose one of the following choices:\n";
	cin >> choice;

	while(((choice < 1) || (choice > 6)) && (!cin.fail()))
	{
		cout << "Oops, try again! ";
		cout<<"Here's the menu again:\n";
		cout<<"1. Cube\n";
		cout<<"2. Sphere\n";
		cout<<"3. Prism\n";
		cout<<"4. Cylinder\n";
		cout<<"5. Cone\n";
		cout<<"6. Quit\n";
		cin >> choice;
	}

	if (cin.fail())
	{
		cout << "Cannot comprehend that choice. Ending range calculation program. ";
		exit(1);
	}
	
	return choice;
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
		cerr<<"Negative numbers cannot be computed. Please choose a positive number.\n";
		cout<<prompt;
		cin>>retVal;
	}
	return retVal;
}
