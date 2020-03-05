#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	unsigned int frequency1{0};
	unsigned int frequency2{0};
	unsigned int frequency3{0};
	unsigned int frequency4{0};
	
	srand(time(NULL));
	
	int i = 1;
	
	while(i++ < 1000) 
	{
		int i = (rand() % 100);
	
		if (i >= 76)
		{
			++frequency1;
		}
		else if (i >= 51)
		{
			++frequency2;
		}
		else if (i >= 26)
		{
			++frequency3;
		}
		else if(i >= 1)
		{
			++frequency4;
		}
	
	}
	
	cout << "  Number" << setw(13) << "Frequency" << endl;
	
	cout << "   1-25  " << setw(13) << ++frequency4
	   << "\n   26-50 " << setw(13) << ++frequency3
	   << "\n   51-75 " << setw(13) << ++frequency2
	   << "\n   76-100" << setw(13) << ++frequency1 << endl;
	
	return 0;
	
}
