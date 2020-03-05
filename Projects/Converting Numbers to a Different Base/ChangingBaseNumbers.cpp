#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main() try
{
	cout << "Enter a number and base";
	
	int num, base;
	
	if (cin >> num >> base)
	{
		if (base < 2|| base > 36)
			throw out_of_range("Invalid base for conversion");
		
		const string digits("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		bool is_neg = num < 0;
		string result;
		
		for (; num; num/= base)
		{
			result.insert(result.begin(), digits[abs(num % base)]);
		}
		
		if(is_neg)
			result.insert(result.begin(), '-');
		
		cout << result << '\n';
	}
	
	else
	{
		cerr << "Invalid input\n";
	}
}

catch (const out_of_range& ex)
{
	cerr << ex.what() << '\n';
}
