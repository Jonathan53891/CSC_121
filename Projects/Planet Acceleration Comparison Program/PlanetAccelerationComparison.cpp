#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double ReadDouble(string prompt)
{
	double retVal=0.0;
	cout<<prompt;
	cin>>retVal;
	while(cin.fail() !=0)
	{
		cin.clear();
		cin.ignore(255,'\n');
		cerr<<"Cannot read input.\n";
		cout<<prompt;
		cin>>retVal;
	}
	return retVal;
}

class Planet
{
	private:
		string Name;
		double Diameter;
		double Mass;
		
	public:
		Planet()
		{
			Name="0";
			SetName();
			Diameter=0;
			SetDiameter();
			Mass=0;
			SetMass();
		}
		
		int SetName()
		{
			cout << "Enter planet name:" << endl;
			cin >> Name;
		}
		
		int SetDiameter()
		{
			Diameter=ReadDouble("Enter the diameter of the planet:");
			while (Diameter < 0)
			{
				cerr << "Diameter value cannot be negative." << endl;
				Diameter=ReadDouble("Enter the diameter of the planet:");
			}
			return 0;
		}
		
		int SetMass()
		{
			Mass=ReadDouble("Enter the mass of the planet:");
			while (Mass < 0)
			{
				cerr << "Mass value cannot be negative." << endl;
				Mass=ReadDouble("Enter the mass of the planet:");
			}
			return 0;
		}
		
		string GetName() {return Name;}
		double GetDiameter() {return Diameter;}
		double GetMass() {return Mass;}
		double GetSurfaceArea() {return 4.0*M_PI*pow(Diameter/2.0,2.0);}
		double GetDensity() {return (4.0/3.0)*M_PI*pow(Diameter/2.0,3.0);}
		double GetGravity() {return (Mass*6.674*pow(10.0,-11.0))/(pow(Diameter/2.0,2.0));}
};


int main()
{
	cout << "Welcome to my planets program." << endl;
	
	Planet Planet1;
	Planet Planet2;
	
	cout<<"The surface area of planet " << Planet1.GetName() << "is: " 
	<< Planet1.GetSurfaceArea() << " and the density is:"
	<< Planet1.GetDensity() << endl;
	
	cout<<"The surface area of planet " << Planet2.GetName() << "is: " 
	<< Planet2.GetSurfaceArea() << " and the density is:"
	<< Planet2.GetDensity() << endl;
	
	if(Planet1.GetGravity()>=Planet2.GetGravity())
	{
		cout<<"Planet " << Planet1.GetName() << " has a larger gravity. The gravity is: " 
		<< Planet1.GetGravity()<< endl;
	}
	
	else
	{
		cout << "Planet " << Planet2.GetName() << " has a larger gravity. The gravity is: " 
		<< Planet2.GetGravity()<<endl;
	}
}
