#include"Line.h"
#include<iostream>
using namespace std;

Line::Line(int x1, int y1, int x2, int y2) :coor_A(x1, y1), coor_B(x2,y2)
{
	cout << "Line()" << endl;
}
Line::~Line()
{
	cout << "~Line()" << endl;
}
void Line::set_A(int x1, int y1)
{
	coor_A.set_x (x1);
	coor_A.set_y (y1);
	cout << "set_A()" << endl;
}
void Line::set_B(int x2, int y2)
{
	coor_B.set_x(x2);
	coor_B.set_y(y2);
	cout << "set_B()" << endl;
}
void Line::print_info()
{
	cout << coor_A.get_x() <<" "<< coor_A.get_y() << endl;
	cout << coor_B.get_x() << " "<< coor_B.get_y() << endl;
}