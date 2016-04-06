#include<string>
#include<iostream>
using namespace std;

class String
{
public:
	String();
	void GetString();
	void GetSubString();
	void Index();
	void Print();
	string StrCopy(string T,string S);
private:
	bool Match(int);
	string str;
	string sub;
	int strlen;
	int sublen;
	int pos;
};

