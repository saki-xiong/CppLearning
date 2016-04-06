//#include"Coordinate.h"
#include"Line.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	Line *p = new Line(1,2,3,4);
	p->print_info();
	delete p;
	/*system("pause");*/
	return 0;
}