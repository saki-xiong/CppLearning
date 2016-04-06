#include"StringClass.h"
//#include<string>
#include<iostream>
using namespace std;
String::String()
{
	str.clear(); 
	sub.clear();
	pos = strlen = sublen = 0;
}

void String::GetString()
{
	cout << "Please Input The MainString :" << endl;
	cin >> str;
	strlen = str.length();
}

void String::GetSubString()
{
	cout << "Please Input The SubString :" << endl;
	cin >> sub;
	sublen = sub.length();
}

void String::Index()
{
	cout << "Index Called !" << endl;
	cout << "Which Position Do You Want To Start Your Index ?" << endl;
	cin >> pos;
	pos--;                            //为符合操作者习惯而设计第一个字符即第一位
	if (pos>strlen - sublen||pos<0)
	{
		cout << "Failed !" << endl;
		return;
	}
	int i, j;
	i = pos;
	j = 0;
	while (i<strlen&&j<sublen)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == sublen)
	{
		cout << "Succed ! " << " Position = " << i - j + 1 << endl << endl;
	}
	else
	{
		cout << "Failed !" << endl << endl;
	}
}


void String::Print()
{
	cout << "Main String = " << str << endl << " Length = " << strlen << endl;
	cout << "SubString = " << sub << endl << " Length = " << sublen << endl << endl;
}

bool String::Match(int i)
{
	for (int j = 0; j<sublen; j++)
	{
		if (str[i + j] != sub[j])
			return false;
	}
	return true;
}