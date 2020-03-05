#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int ReadInt(string prompt);
int Parse(string input);

void encryption(int key,string output,string text);
void decryption(int key,string output,string text);

string SetOutputFile();
string OpenInput(string& text);

int ReadInt(string prompt) 
{
	string response="0";
	cout<<prompt;
	cin>>response;
	while (Parse(response)!=0) 
	{
		cin.clear();
		cin.ignore(255,'\n');
		cerr<<"Cannot Read Input."<<endl;
		cout<<prompt<<endl;
		cin>>response;
	}
	cin.clear();
	cin.ignore(255,'\n');
	return stoi(response);
}

int Parse(string input)
{
	for(int i=0;i<input.length();i++){
		if(isdigit(input[i])==0){
		return 1;
		}
	}
	return 0;
}

int main()
{
	int choice=0;
	{
		while(choice !=3)
		{ 
			cout<<"1) Encrypt"<<endl;
			cout<<"2) Decrypt"<<endl;
			cout<<"3) Quit"<<endl;
			
			choice = ReadInt("Would you like to encrypt or decrypt a file? ");
		
			if (choice==1)
			{
				string text;
				OpenInput(text);
				string output=SetOutputFile();
				int key=ReadInt("Enter Encryption Key: \n");
				encryption(key,output,text);		
			}
			if (choice==2)
			{
				string text;
				OpenInput(text);
				string output=SetOutputFile();
				int key=ReadInt("Enter Encryption Key: \n");
				decryption(key,output,text);	
			}
			if (choice > 3 || choice < 1)
				cout<<"Cannot Read Input"<<endl;
		}
	}
	
}

void gather_text(istream& source,string& text)
{
	string line;
	source.peek();
	while (!source.eof())
	{
		getline(source, line);
		text+=line+'\n';
		source.peek();
	}
	return;
}

string OpenInput(string& text) 
{
	string fname;
	ifstream text_file;
	cout<<"Enter Filename: \n";
	getline(cin,fname);
	text_file.open(fname);
	while (!text_file)
	{
		text_file.close();
		text_file.clear();
		cout<<endl<<"Unable to Open "<<endl<<"Enter Filename:  "<<endl;
		getline(cin, fname);
		text_file.open(fname);
	}
	gather_text(text_file, text);
	return text;
}

string SetOutputFile() 
{
	string output;
	cout<<"Enter Output Filename: "<<endl;
	cin>>output;
	return output;
}

void encryption(int key,string output,string text) 
{
	ofstream outputfile;
	string encrypted, sKey;
	int keyBit;
	sKey=to_string(key);
	int keylen=sKey.length();
	int i=0;

	outputfile.open(output);

	for (char c:text) 
	{
		keyBit=stoi(sKey.substr(i,1));
		if (isalpha(c)) 
		{
			if (isupper(c)) 
				c=static_cast<char>(((c-'A'+keyBit)%26)+'A');
			else 
				c=static_cast<char>(((c-'a'+keyBit)%26)+'a');
			i=(i+1)%keylen;
		}
		encrypted=encrypted+c;
	}
	if (outputfile.is_open()) 
		outputfile<<encrypted;
	else 
		cout<<"Unable to Open Output File."<<endl;
		
	outputfile.close();
	
	return;
}

void decryption(int key,string output,string text) 
{
	ofstream outputfile;
	string encrypted, sKey;
	int keyBit;
	sKey=to_string(key);
	int keylen=sKey.length();
	int i=0;

	outputfile.open(output);

	for (char c:text)
	{
		keyBit=stoi(sKey.substr(i, 1));
		if (isalpha(c))
		{
			if (isupper(c)) 
				c=static_cast<char>(((c+26-'A'-keyBit)%26)+'A');
			else 
				c=static_cast<char>(((c+26-'a'-keyBit)%26)+'a');
			i=(i+1)%keylen;
		}
		encrypted=encrypted+c;
	}

	if (outputfile.is_open()) 
		outputfile<<encrypted;
	else 
		cout<<"Unable to Open Output File."<<endl;

	outputfile.close();

	return;
}

