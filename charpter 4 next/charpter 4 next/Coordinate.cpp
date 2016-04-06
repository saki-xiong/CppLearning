#include"Coordinate.h"
#include<iostream>
using namespace std;
Coordinate::Coordinate()			//对应无参
{
	cout << "Coordinate()1" << endl;
}
Coordinate::Coordinate(int x, int y) :m_ix(x), m_iy(y)		//对应有参
{
	cout << "Coordinate()2" << endl;

}
Coordinate::~Coordinate()
{
	cout << "~Coordinate()" << endl;
}
void Coordinate::set_x(int x)
{
	m_ix = x;
	cout << "set_x" << endl;
}
int Coordinate::get_x()
{
	return m_ix;
	cout << "get_x" << endl;
}
void Coordinate::set_y(int y)
{
	m_iy = y;
	cout << "set_y" << endl;
}
int Coordinate::get_y()
{
	return m_iy;
	cout << "get_y" << endl;
}
