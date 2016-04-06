#include"Coordinate.h"
class Line{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();
	void set_A(int x1, int y1);
	void set_B(int x2, int y2);
	void print_info();
private:
	Coordinate coor_A;
	Coordinate coor_B;
};