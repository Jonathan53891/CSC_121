#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <array>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

double ReadDouble(string prompt);

int ReadInt(string prompt, int min);
int ReadInt(string prompt, int min, int max);
int Parse(string response, int a);
int Parse(string response, int a, double min);
int Parse(string response, int a, double min, double max);
int Menu();

const double CaveCons = 6.67259 * pow(10, -11);

class Planet 
{
	private: //members
		string name;
		double diameter;
		double mass;
		double density;
		double surface_area;
		double gravity;
		double volume;
	public:
		Planet(string NewName) //default constructor
		{
			name = NewName;
			diameter = 0.0;
			mass = 0.0;
			density = 0.0;
			surface_area = 0.0;
			gravity = 0.0;
			volume = 0.0;
		}

	void setName(string prompt) 
	{
		cout << prompt;
		cin >> name;
	}
	void setMass(string prompt) 
	{
		while (mass == 0) 
		{
			mass = ReadInt(prompt, 0);
			
			if (mass == 0) 
			{
				cout << "Mass can't be zero.";
			}
		}
	}
	void setDiameter(string prompt) 
	{
		while (diameter == 0) 
		{
			diameter = ReadInt(prompt, 0);
			
			if (diameter == 0) 
			{
				cout << "Diameter can't be zero.";
			}
		}
	}
	void Force_setName(string Newname) 
	{
		name = Newname;
	}

	double calcGravity(double m, double d) 
	{
		return (CaveCons * m / (pow(d / 2, 2)));
	}
	
	//accessors              //input values
	string getName()        { return name; }
	double getMass()        { return mass; }
	double getDiameter()    { return diameter; }
	double getSurfaceArea() { return surface_area; }
	double getVolume()      { return volume; }
	double getGravity()     { return gravity; }
	double getDensity()     { return density; }
	
	//accessors                                     //calculations
	double calcSurfaceArea(double d)               { return 4*M_PI*pow(d/2,2); }
	double calcVolume(double d)                    { return 4*M_PI*pow(d/2,3)/3; }
	double calcDensity(double mass, double volume) { return mass/volume; }
	
	//mutators
	void SetPlanet() 
	{
		setMass("What is the mass of " + name + " (in kg)? ");
		setDiameter("What is the diameter of " + name + " (in m)? ");
		recalculate();
	}

	void recalculate() 
	{
		surface_area = calcSurfaceArea(diameter);
		volume = calcVolume(diameter);
		density = calcDensity(mass, volume);
		gravity = calcGravity(mass, diameter);
		return;
	}
	
	bool displayPlanet(ostream & out, bool verbose)
	{
	    if(verbose == true)
	    {
	        cout << "Planet Name: " << name << endl;
	        cout << "Mass: " << mass << endl;
	        cout << "Diameter: " << diameter << endl;
	    }
	    
	    else
	    {
	        cout << name << endl;
	        cout << mass << endl;
	        cout << diameter << endl;
	    }
	}

};

void addPlanet(vector<Planet>& planetList);     // 1) Add planet
void deletePlanet(vector<Planet>& planetList);  // 2) Delete planet
void searchPlanet(vector<Planet>& planetList);  // 3) Search for planet
void displayPlanet(vector<Planet>& planetList); // 4) List all planets
void sortPlanets(vector<Planet>& planetList);   // 5) Sort planets alphabetically
void savePlanets(vector<Planet>& planetList);   // 6) Write list of planets to file

void Swap(vector<Planet>& name, int a, int b);  // allows "sortPlanets()" to swap positions of planets in list

int main()
{
	vector<Planet> planetList;
	int choice = -1;

	while (choice != 6) 
	{
		choice = Menu();
		switch (choice) 
		{
			case 1://Add Planet
				addPlanet(planetList);
				break;
			
			case 2://Delete Planet
				deletePlanet(planetList);
				break;
			
			case 3://Search For Planet
				searchPlanet(planetList);
				break;
			
			case 4://List all Planets
				displayPlanet(planetList);
				break;
			
			case 5://Sort planets alphabetically
				sortPlanets(planetList);
				break;
			
			case 6://Write the planets to file
				savePlanets(planetList);
				break;
			
			case 7://Quit
			{				
				cout << "Thanks for participating in my Planet program. See you around!" << endl;
				
				return 0;
			}
			
			default:
				cout<<"Choice invalid"<<endl;
				choice = 0;
				break;
		}
	}
}

//Menu
int Menu() 
{
	int choice = 0;
	
	cout << "------Jonathan's Planets Program------" << endl;
	cout << "1) Add Planet" << endl;
	cout << "2) Delete Planet" << endl;
	cout << "3) Search For Planet" << endl;
	cout << "4) List All Planets" << endl;
	cout << "5) Sort By Name" << endl;
	cout << "6) Save Planets To File" << endl;
	cout << "7) Quit" << endl;
	
	choice = ReadInt("Enter your choice (1-7):", 1 , 7);
	return choice;
}

// 1) Add planet
void addPlanet(vector<Planet>& planetList) 
{
	string objectName;
	cout << "What would you like to name the planet?\n";
	cin >> objectName;
	planetList.push_back(objectName);
	
	planetList[planetList.size() - 1].SetPlanet();

	return;
}

// 2) Delete planet
void deletePlanet(vector<Planet>& planetList) 
{
	string removeMe;
	cout << "Which planet should be removed?\n";
	cin >> removeMe;
	int j = 0;
	
	for (int i = 0; i < planetList.size(); i++) 
	{
		if (planetList[i].getName() == removeMe) 
		{
			planetList.erase(planetList.begin() + i);
			cout << "Removed " << removeMe << endl;
			j++;
			i--;
		}
	}

	if (j == 0) 
	{
		cout << "Couldn't find any planets named " << removeMe << " to be deleted.\n";
	}

	return;
}

// 3) Search for a specific planet
void searchPlanet(vector<Planet>& planetList) 
{
	string findMe;
	cout << "Enter the planet you would like to search for: \n";
	cin >> findMe;
	int j = 0;

	for (int i = 0; i < planetList.size(); i++) 
	{
		if (planetList[i].getName() == findMe) 
		{
			cout << findMe << " was found at position " << i + 1 << ".\n" << endl;
			cout << findMe << " has a mass of " << planetList[i].getMass() << " kg" << endl;
			cout << findMe << " has a diameter of " << planetList[i].getDiameter() << " m" << endl;
			cout << findMe << " has a surface area of " << planetList[i].getSurfaceArea() << " m^2" << endl;
			cout << findMe << " has a volume of " << planetList[i].getVolume() << " m^3" << endl;
			cout << findMe << " has a density of " << planetList[i].getDensity() << " kg/m^3" << endl;
			cout << findMe << " has a gravity of " << planetList[i].getGravity() << " m/s^2" << endl;
			j++;
		}
	}

	if (j == 0) 
	{
		cout << "Couldn't find any planets named " << findMe << ".\n";
	}

	return;
}

// 4) List all planets
void displayPlanet(vector<Planet>& planetList) 
{
	for (int i = 0; i < planetList.size(); i++) 
	{
		cout << planetList[i].getName() << " has a mass of " << planetList[i].getMass() << " kg"  
		<< ", diameter of " << planetList[i].getDiameter() << " m"
		<< ", surface area of " << planetList[i].getSurfaceArea() << " m^2"
		<< ", volume of " << planetList[i].getVolume() << " m^3"
		<< ", density of " << planetList[i].getDensity() << " kg/m^3"
		<< ", gravity of " << planetList[i].getGravity() << " m/s^2" << endl;
	}
	
	if (planetList.size() == 0) 
	{
		cout << "No planets have been created yet\n";
	}
	
	return;
}

// 5) Sort planets alphabetically
void sortPlanets(vector<Planet>& planetList) 
{
	int jMax = planetList.size();
	for (int i = 0; i < planetList.size() - 1; i++) 
	{
		for (int j = 0; j < jMax - 1; j++) 
		{
			string strA = planetList[j].getName();
			string strB = planetList[j+1].getName();
			
			transform(strA.begin(),strA.end(),strA.begin(), ::tolower);
			transform(strB.begin(),strB.end(),strB.begin(), ::tolower);
			
			if (strA > strB)
			{
				Swap(planetList, j, j + 1);
			}
		}
		jMax--;
	}
	return;
}

void Swap(vector<Planet>& name, int a, int b) 
{
	Planet temp("temp");

	temp = name[a];
	name[a] = name[b];
	name[b] = temp;

	return;
}

// 6) Save list of planets to file
void savePlanets(vector<Planet>& planetList) 
{
	ofstream outputFile;
	string oName;
	cout<<"Enter Output Filename: "<<endl;
	cin>>oName;
	outputFile.open(oName);
	if (outputFile.is_open()) 
	{
		for (size_t i=0;i<planetList.size();i++) 
		{
			outputFile<<"Name: "<<planetList[i].getName()<<endl;
			
			outputFile << planetList[i].getName() << " has a mass of " << planetList[i].getMass() << " kg" << endl;
			outputFile << planetList[i].getName() << " has a diameter of " << planetList[i].getDiameter() << " m" << endl;
			outputFile << planetList[i].getName() << " has a surface area of " << planetList[i].getSurfaceArea() << " m^2" << endl;
			outputFile << planetList[i].getName() << " has a volume of " << planetList[i].getVolume() << " m^3" << endl;
			outputFile << planetList[i].getName() << " has a density of " << planetList[i].getDensity() << " kg/m^3" << endl;
			outputFile << planetList[i].getName() << " has a gravity of " << planetList[i].getGravity() << " m/s^2" << endl;
		}
		cout<<"\nSuccess! Planets Saved to File.\n"<<endl;
	}
	else 
		cout<<"Unable to Save to File. "<<endl;
	outputFile.close();
	return;
}

// 7) Quit

	// cout << "Thanks for participating in my Planet program. See you around!" << endl;
	// return 0;
	
double ReadDouble(string prompt)
{
	string response = "0.0";
	cout << prompt;
	cin >> response;
	while (Parse(response, 0) != 0) 
	{
		cin.clear();
		cin.ignore(255, '\n');
		cerr << "Input was not a number." << endl;
		cout << prompt << endl;
		cin >> response;
	}
	cin.clear();
	cin.ignore(255, '\n');
	return stod(response);
}

int ReadInt(string prompt, int min) 
{
	string response = "0";
	cout << prompt;
	cin >> response;
	while (Parse(response, 1, min) != 0) 
	{
		cin.clear();
		cin.ignore(255, '\n');
		cerr << "Input was not an integer or not greater than " << min << "." << endl;
		cout << prompt << endl;
		cin >> response;
	}
	cin.clear();
	cin.ignore(255, '\n');
	return stoi(response);
}

int ReadInt(string prompt, int min, int max) 
{
	string response = "0";
	cout << prompt;
	cin >> response;
	while (Parse(response, 1, min, max) != 0) 
	{
		cin.clear();
		cin.ignore(255, '\n');
		cerr << "Input was not an integer or not between " << min << " and " << max << "." << endl;
		cout << prompt << endl;
		cin >> response;
	}
	cin.clear();
	cin.ignore(255, '\n');
	return stoi(response);
}

int Parse(string response, int a)
{
	int point = 0;
	int negative = 0;

	if (a == 1) 
	{
		point++;
	}

	for (int i = 0; i < response.length(); i++) 
	{
		if (isdigit(response[i]) != 0) 
		{
			negative++;
		}
		else if (point == 0 && response[i] == '.') 
		{
			point++;
		}
		else if (negative == 0 && response[i] == '-') 
		{
			negative++;
		}
		else 
		{
			return 1;
		}
	}
	return 0;
}

int Parse(string response, int a, double min)
{
	int point = 0;
	int negative = 0;

	if (a == 1) 
	{
		point++;
	}

	for (int i = 0; i < response.length(); i++) 
	{
		if (isdigit(response[i]) != 0) 
		{
			negative++;
		}
		else if (point == 0 && response[i] == '.') 
		{
			point++;
		}
		else if (negative == 0 && response[i] == '-') 
		{
			negative++;
		}
		else 
		{
			return 1;
		}
	}
	if (stod(response) < min) {
		return 1;
	}
	return 0;
}

int Parse(string response, int a, double min, double max)
{
	int point = 0;
	int negative = 0;

	if (a == 1) 
	{
		point++;
	}

	for (int i = 0; i < response.length(); i++) 
	{
		if (isdigit(response[i]) != 0) 
		{
			negative++;
		}
		else if (point == 0 && response[i] == '.') 
		{
			point++;
		}
		else if (negative == 0 && response[i] == '-') 
		{
			negative++;
		}
		else 
		{
			return 1;
		}
	}
	
	if (stod(response) < min || stod(response) > max) 
	{
		return 1;
	}
	
	return 0;
}
