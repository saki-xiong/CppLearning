#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//º¯ÊýÄ£°å
template<typename T>

void display(T a)
{
	cout << a << endl;
}

template<typename T,typename S>

void display(T a,S s)
{
	cout << a << endl;
	cout << s << endl;
}

template<typename T, int size>

void display(T a)
{
	for (i = 0; i < size; i++)
	{
		cout << a << endl;
	}
}

int main(void)
{
	display<int>(5);
	display<int, string>(1024, "hello,world!");

	system("pause");
	return 0;
}