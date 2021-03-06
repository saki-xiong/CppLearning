#include <iostream> 
#include <stack> 
#include <vector> 

using namespace std;

#ifndef MIGONG_H 
#define MIGONG_H 
/////////////////// 
///////矩阵类////// 
/////////////////// 
class Matrix{
	int* m;
	int row, col;
	bool iscreate;
public:
	Matrix(){ m = 0; iscreate = false; };
	~Matrix() { Release(); };
	bool Create(int, int);
	int& operator () (int, int);
	int GetRow(){ return row; };
	int GetCol(){ return col; };
	void Release();
	void Show(char, char);
};

bool Matrix::Create(int r, int c)
{
	if (r <= 0 || c <= 0) return false;

	Release();

	row = r;
	col = c;
	m = new int[row*col];

	for (int i = 0; i<row*col; i++)
	{
		*(m + i) = 0;
	}
	iscreate = true;
	return true;
}

int& Matrix::operator ()(int r, int c)
{
	return *(m + r*col + c);
}

void Matrix::Release()
{
	if (iscreate)
	{
		row = col = 0;
		if (m) delete[] m;
		m = 0;
	}
	iscreate = false;
}

void Matrix::Show(char blk = '#', char nblk = ' ')
{
	int i, j;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			if (*(m + i*col + j) == 0)
				cout << nblk;
			else
				cout << blk;
		}
		cout << endl;
	}
}
///////////////////////////// 
////迷宫相关数据结构的定义/// 
///////////////////////////// 
struct offsets{
	int a, b;
};

enum directions{
	_S = 0,
	_E,
	_N,
	_W
};

struct item{
	int row, col, dir;
};

class Migong{
	static offsets move[4];
	Matrix maze;
	Matrix mark;
	int row;
	int col;
	int desr;
	int desc;
	stack<item> stk;
	bool iscreate;
	int pathlength;
	bool GetPath();
	bool IsInPath(int, int);
public:
	Migong(){ issolved = false; result = 0; pathlength = row = col = 0; iscreate = false; };
	~Migong(){ Release(); };
	bool Create(int*, int, int, int, int);
	void Solve();
	void Release();
	void OutputMaze();
	void ShowSolve(char, char);
public:
	bool issolved;
	item* result;
};

offsets Migong::move[4] = { { 1, 0 }, { 0, 1 },
{ -1, 0 }, { 0, -1 } };

//////////////////////////// 
//迷宫数据应该是不含边框的// 
//////////////////////////// 
bool Migong::Create(int* m, int r, int c, int desrow = -1, int descol = -1)
{
	if (r <= 0 || c <= 0) return false;

	Release();

	if (desrow == -1 || descol == -1)
	{
		desr = r;
		desc = c;
	}
	else
	{
		desr = desrow;
		desc = descol;
	}

	row = r;
	col = c;
	maze.Create(r + 2, c + 2);
	mark.Create(r + 2, c + 2);

	int i, j;

	for (i = 0; i<r + 2; i++)
	{
		for (j = 0; j<c + 2; j++)
		{
			if (j == 0 || j == c + 1 || i == 0 || i == r + 1)
			{
				mark(i, j) = maze(i, j) = 1;

			}
			else
			{
				mark(i, j) = 0;
				maze(i, j) = m[((i - 1)*col + j - 1)];
			}
		}
	}
	return iscreate = true;
}

bool Migong::GetPath()
{
	mark(1, 1) = 1;
	item temp;
	temp.col = 1;
	temp.row = 1;
	temp.dir = _S;
	stk.push(temp);

	while (!stk.empty())
	{
		temp = stk.top();
		stk.pop();

		int i = temp.row;
		int j = temp.col;
		int d = temp.dir;

		while (d<4)
		{//根据当前点的状态确定下一个搜索点 
			int g = i + move[d].a;
			int h = j + move[d].b;

			if (g == desr && h == desc)
			{
				return true;
			}
			//如果这个点不是障碍点且没有被搜索过那么可以对这个点进行搜索 
			if (maze(g, h) == 0 && mark(g, h) == 0)
			{
				mark(g, h) = 1;
				temp.row = g;
				temp.col = h;
				temp.dir = d + 1;
				stk.push(temp);
				i = g;
				j = h;
				d = _S;//对一下个点进行搜索 
			}
			else d++;
		}
	}
	return false;
}

void Migong::Solve()
{
	issolved = GetPath();
	if (issolved)
	{
		pathlength = stk.size();
		result = new item[pathlength];
		for (int i = 0; i<pathlength; i++)
		{
			*(result + i) = stk.top();
			stk.pop();
			// cout<<"("<<(*(result+i)).row<<","<<(*(result+i)).col<<")"<<endl; 
		}
	}
	while (!stk.empty())
		stk.pop();
}

void Migong::Release()
{
	if (iscreate)
	{
		maze.Release();
		mark.Release();
		row = col = 0;
		if (result)
			delete[] result;
		result = 0;
		while (!stk.empty())
			stk.pop();
	}
	iscreate = false;
	issolved = false;
	pathlength = 0;
}

void Migong::OutputMaze()
{
	if (!iscreate) return;
	maze.Show();
}

bool Migong::IsInPath(int r, int c)
{
	if (!iscreate || !issolved)
		return false;

	item temp;
	for (int i = 0; i<pathlength; i++)
	{
		temp = *(result + i);
		if ((temp.row == r) && (temp.col == c))
			return true;
	}

	return false;
}

void Migong::ShowSolve(char blk = '#', char s = 'o')
{
	if (!iscreate) return;
	if (!issolved)
	{
		cout << "无解" << endl;
	}
	else
	{
		int i, j;
		for (i = 0; i<row + 2; i++)
		{
			for (j = 0; j<col + 2; j++)
			{
				if ((i == 1 && j == 1) || (i == desr && j == desc))
				{
					cout << s;
				}
				else if (maze(i, j) == 1)
				{
					cout << blk;
				}
				else
				{
					if (IsInPath(i, j))
						cout << s;
					else
						cout << ' ';
				}
			}
			cout << endl;
		}
	}
}

////////////////////// 
//////穷举所有路径//// 
////////////////////// 
offsets mymove[4] = { { 1, 0 }, { 0, 1 },
{ -1, 0 }, { 0, -1 } };

struct node
{
	int row, col;
};

vector<node> path;
int mycount;
bool IsReachable(Matrix& maze, Matrix& mark, node beg, node des)
{
	if (beg.row == des.row&&beg.col == des.col)
	{//如果达到的话那么显示路径 
		mycount ++;
		cout << "第" << mycount << "条路径:" << endl;
		for (int i = 0; i<path.size(); i++)
			cout << "(" << path[i].row << "," << path[i].col << ")";
		cout << "(" << des.row << "," << des.col << ")";
		cout << endl;
		return false;
	}
	if (maze(beg.row, beg.col) == 1 || mark(beg.row, beg.col) == 1)
	{
		return false;
	}

	path.push_back(beg);
	mark(beg.row, beg.col) = 1;

	node nextnode;

	for (int i = _S; i<_W + 1; i++)
	{
		nextnode.row = beg.row + mymove[i].a;
		nextnode.col = beg.col + mymove[i].b;

		IsReachable(maze, mark, nextnode, des);
	}

	path.resize(path.size() - 1);
	mark(beg.row, beg.col) = 0;

	return false;//如果不是穷举的话应该根据for循环的结果重新设置返回值 
}

/*
参数maze,mark为迷宫长宽均加二的矩阵
desr,desc为出口点
*/
void FindAllPath(Matrix& maze, Matrix& mark, int desr, int desc)
{
	node first, last;
	first.row = 1;
	first.col = 1;
	last.row = desr;
	last.col = desc;

	IsReachable(maze, mark, first, last);

	path.clear();
}

/*
m迷宫矩阵数据
r,c行和列的大小
desr,desc目标位置
*/
void ShowAllPath(int* m, int r, int c, int desr = -1, int desc = -1)
{
	Matrix maze, mark;
	maze.Create(r + 2, c + 2);
	mark.Create(r + 2, c + 2);

	if (desr == -1 || desc == -1)
	{
		desr = r;
		desc = c;
	}

	int i, j;

	for (i = 0; i<r + 2; i++)
	{
		for (j = 0; j<c + 2; j++)
		{
			if (j == 0 || j == c + 1 || i == 0 || i == r + 1)
			{
				mark(i, j) = maze(i, j) = 1;

			}
			else{
				mark(i, j) = 0;
				maze(i, j) = m[((i - 1)*c + j - 1)];
			}
		}
	}

	mycount = 0;
	FindAllPath(maze, mark, desr, desc);

	maze.Release();
	mark.Release();
}
#endif