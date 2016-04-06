class Coordinate
{
public:
	Coordinate();
	Coordinate(int x,int y);
	~Coordinate();
	void set_x(int x);
	int get_x();
	void set_y(int y);
	int get_y();
private:
	int m_ix;
	int m_iy;
};