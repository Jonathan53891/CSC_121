#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <array>


using namespace std;

void Display(vector<double>& l);
void Input(vector<double>& l);
void SelectionSort(vector<double>& l);
void Pass(vector<double>& l);
void Swap(vector<double>& l);
void InsertionSort(vector<double>& l);
void BubbleSort(vector<double>& l);
long BiSearch(vector<double>& l, double value, long left, long right);

int main()
{
	srand(time(0));
	vector<double> l;
	
	int num=0;
	cout<<"# of values?\n";
	cin>>num;
	
	for(int i=0; i<num; i++)
	{
		l.push_back(rand() % 100 + 1);
	}
	
	vector<double> list2 = l;
	vector<double> list3 = l;
	
	Display(l);
	long start1=clock();
	BubbleSort(l); 
	long stop1=clock();
	
	Display(list2);
	long start2=clock();
	SelectionSort(list2);
	long stop2=clock();
	
	Display(list3);
	long start3=clock();
	InsertionSort(list3);
	long stop3=clock();
	
	cout << "\nThe amount of time it took to sort using bubble sort is " << (stop1 - start1)/(CLOCKS_PER_SEC / 1000.0) << " milliseconds" << endl;
	cout << "The amount of time it took to sort using selection sort is " << (stop2 - start2)/(CLOCKS_PER_SEC / 1000.0) << " milliseconds" << endl;
	cout << "The amount of time it took to sort using insertion sort is " << (stop3 - start3)/(CLOCKS_PER_SEC / 1000.0) << " milliseconds" << endl;
	
	return 0;
}

void Display(vector<double>& l)
{
	if(l.empty()!=0)
	{
		cout<<"List is empty\n";
	}
	
	else
	{
		long len=l.size();
		
		for(long i=0; i<len; i++)
		{
			cout.width(10);
			cout.precision(4);
			cout.setf(ios::fixed|ios::showpoint|ios::right);
			cout<<l[i]<<'\t';
		}
	}
	
	return;
}

//void Input(vector<double>& l)
//{
	//int num=0;
	//cout<<"# of values?\n";
	//cin>>num;
	//double num = 0.0;
	//double number = 0.0;
	
	//for(int i=0; i<num; i++)
	//{
		//cout<<"Enter the numbers you want to store:";
		//cin>>num;
		//l.push_back(rand() % 100 + 1);
	//}
	
	//return;
//}

//bubble sort
void BubbleSort(vector<double>& l) 
{
    bool repeat_flag = false;
    for (long i = 0; i < l.size()-1; i++) 
    {
       double item1 = l[i];
       double item2 = l[i+1];

       if (item1 > item2) 
       {
           l[i] = item2;
           l[i+1] = item1;
           repeat_flag = true;
       }
    }
    if (repeat_flag) 
    {
        BubbleSort(l);
    }
    return;

}

void Swap(double& x, double& y)
{
	double tmp = x;
	x = y;
	y = tmp;
}


void Pass(vector<double>& l)
{
	long len=l.size();
	
	for(long i=0; i<len-1; i++)
	{
		if(l[i]>l[i+1])
		{
			Swap(l[i],l[i+1]);
		}
	}
}

void Sort(vector<double>& l)
{
	long len = l.size();
	for(long i=0; i<len; i++)
	{
		Pass(l);
	}
}

//Selection Sort
bool SelectionPass(vector<double>& l, long len)
{
	bool isSorted=true;
	for(long i=0; i<len-1; i++)
	{
		if(l[i]>l[i+1])
		{
			Swap(l[i],l[i+1]);
			isSorted=false;
		}
	}
	
	return isSorted;
}

void SelectionSort(vector<double>& l)
{
	long len = l.size();
	
	while(SelectionPass(l,len)==false)
	{
		len--;
	}
}
//Insertion Sort
void InsertionSort(vector<double>& l)
{
	int i,key,j;
	long len = l.size();
	
	for(long i=1;i<len-1; i++)
	{
		key = l[i];
		j = i-1;
		long loc = BiSearch(l,key, 0, j);
		while(j >= loc)
		{
			l[j+1] = l[j];
			j = j-1;
		}
		
		l[loc] = key;
	}
}

//binary search
long BiSearch(vector<double>& l, double value, long left, long right)
{
	//long left = 0;
	//long right = l.size()-1;
	long mid = 0;
	long index = -1;
	bool done = false;
	
	while(done == false && right >= 0)
	{
		mid = (left+right)/2;
		
		if(l[mid]==value) //if(Equal(l[mid],value)==true)
		{
			index = mid;
			done = true;
		}
		
		else if(l[mid]>value)
		{
			right=mid-1;
		}
		
		else if(l[mid]<value)
		{
			left=mid+1;
		}
		if(left>right)
		{
			done=true;
		}
	}
	
	return mid;
}

bool Insert(vector<double>& l,double value,long pos)
{
	bool rv=false;
	
	if(pos>=0 && pos<=l.size())
	{
		try
		{
			l.push_back(0.0);
			for(long i=l.size()-1; i>pos;i--)
			{
				l[i]=l[i-1];
			}
			l[pos]=value;
			rv=true;
		}
		catch(exception e)
		{
			cerr<<e.what();
		}
	}
	
	bool Delete(vector<double>&l, long pos);
	{
		bool rv=false;
		
		if(pos>=0 && pos<l.size())
		{
			try
			{
				for(long i=l.size()-1; i>pos;i++)
				{
					l[i]=l[i+1];
				}
				l.pop_back();
				rv=true;
			}
			catch(exception e)
			{
				cerr<<e.what();
			}
		}
		else
		{
			cerr<<"Position out of range\n";
		}
		return rv;
	}
}

//linear search
long FindLarger(vector<double>& l,double value)
{
	long rv=0;
	if(l.empty() !=0)
	{
		while(rv<l.size() && l[rv]<value)
		{
			rv++;
		}
	}
	return rv;
}

bool InsertSort(vector<double>& l,double value)
{
	long pos=FindLarger(l,value);
	return Insert(l,value,pos);
}

//bool Equal(double v1,double v2)
//{
	//double low = v1 - 0.00005;
	//double high = v2 + 0.00005;
	
	//bool rv = false;
	
	//if(v2 > low && v2 < high)
	//{
		//rv = true;
	//}
	
	//return rv;
//}

#endif
