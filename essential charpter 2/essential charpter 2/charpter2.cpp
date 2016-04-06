/*E2.1*/
//#include<iostream>
//using namespace std;

//extern bool fibon_elem(int, int&);
//
//void main()
//{
//	int pos, elem;
//	bool more = true;
//	char ch;
//	while (more)
//	{
//		cin >> pos;
//		if (fibon_elem(pos, elem))
//			cout << pos<<elem<<endl;
//		cin >> ch;
//		if (ch != 'y')
//			more = false;
//	}
//}

/*E2.2*/
//#include<iostream>
//using namespace std;
//#include <vector>
//#include<string>
//void main()
//{
//	vector <int> vec;
//	int size;
//	const string num_type("pentagonal nummeric series");
//	bool cal_elem(vector<int> &vec, int size);
//	void display(vector<int> &vec,const string &num_type,ostream &os=cout);
//	cin >> size;
//	cal_elem(vec,size);				//重要，引用传递中函数调用时不用加&，但函数声明时要加,函数定义中也要加
//	display(vec,num_type);
//}
//

//
//void display(vector<int> &vec, const string &num_type,ostream &os)	
																			/*默认参数的决议：一、从参数列表的右边开始决议；
																			二、默认值只能指定一次，可以是声明时也可以是定义时，一般选择在声明时。*/
//{
//	os<< "num_type";
//	for (int i = 0; i < vec.size(); i++)
//		os << vec[i] << ' ';
//}
//bool cal_elem(vector<int> &vec,int size)
//{
//	if (size <= 0 || size > 100)									//检测是否溢出
//	{
//		cout << "invalid position:" << size << endl;
//		return false;
//	}
//	int dent;
//	for (int i = vec.size()+1; i <= size; i++)				
//	{
//		dent = i*(3 * i - 1)/2;				//数列的产生
//		vec.push_back(dent);
//	}
//	return true;
//}

/*E2.3  编译出错，inline函数的定义要放在头文件中*/
//#include<iostream>
//using namespace std;
//#include <vector>
//#include<string>
//
//void main()
//{
//	vector <int> vec;
//	int size;
//	const string num_type("pentagonal nummeric series");
//	bool cal_elem(vector<int> &vec, int size);
//	void display(vector<int> &vec,const string &num_type,ostream &os=cout);
//	extern  void generate_elem(vector<int> &vec, int size);
//
//	cin >> size;
//	cal_elem(vec,size);				
//	display(vec,num_type);
//}
//
//void display(vector<int> &vec, const string &num_type,ostream &os)	
//{
//	os<< "num_type";
//	for (int i = 0; i < vec.size(); i++)
//				os << vec[i] << ' ';
//}
//
//void generate_elem(vector<int> &vec, int size)
//{
//	int dent;
//	for (int i = vec.size() + 1; i <= size; i++)
//	{
//		dent = i*(3 * i - 1) / 2;				
//		vec.push_back(dent);
//	}
//}
// inline bool cal_elem(vector<int> &vec,int size)
//{
//	if (size <= 0 || size > 100)									
//	{
//		cout << "invalid position:" << size << endl;
//		return false;
//	}
//	if (size > vec.size())
//		generate_elem(vec,size);
//	return true;
//}


/*E2.4  局部静态对象的使用*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void main()
//{
//	int pos;
//	vector <int> *generate_elem(int pos);
//	bool cal_elem(int pos);
//	cin >> pos;
//	cal_elem(pos);
//}
//vector <int> *generate_elem(int pos)					//返回值为地址
//{
//	static vector<int> elem;
//	int dent;
//	for (int i =1; i <= pos; i++)
//	{
//		dent = i*(3 * i - 1) / 2;
//		elem.push_back(dent);
//	}
//	return &elem;
//}
//
//
// bool cal_elem( int pos)
//{
//	void display(vector<int> &vec);						//在哪里需要调用就要在哪个函数中声明
//	if (pos <= 0 || pos > 100)									
//	{
//		cout << "invalid position:" << pos << endl;
//		return false;
//	}
//	vector <int> *pent = generate_elem(pos);				//返回值为地址的函数调用
//	display(*pent);											//vector地址的解引用
//	return true;
//}
// void display(vector<int> &vec)
// {
//	 for (int i = 0; i < vec.size(); i++)
//		 cout << vec[i] << ' ';
//	 cout << endl;
// }


/*E2.5  函数重载*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int max(int num1, int num2)
//{
//	return num1 > num2 ? num1 : num2;
//}
//float max(float num1, float num2)
//{
//	return num1 > num2 ? num1 : num2;
//}
//int max(const vector<int> &vec)
//{
//	return *max_element(vec.begin(), vec.end());
//}
//float max(const vector<float> &vec)
//{
//	return *max_element(vec.begin(), vec.end());
//}
//int max(const int *parray, int size)
//{
//	return *max_element(parray, parray + size);
//}
//float max(const float *parray, int size)
//{
//	return *max_element(parray, parray + size);
//}
//
//
//void main()
//{
//	int iarray[] = { 1, 100, 89, 66, 578 };
//	vector <int> ivec(iarray, iarray + 5);			//vector的另一种初始化形式
//	float farray[] = { 1.5, 100.5, 89.5, 66.5, 578.5 };
//	vector <float> fvec(farray, farray + 5);
//	int imax = max((max(ivec)), max(iarray,5));
//	float fmax = max((max(fvec)), max(farray,5));
//	cout << imax<<endl;
//	cout << fmax << endl;
//}

/*E2.6  模板函数*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//template <typename Type>
//Type max1(Type num1, Type num2)
//{
//	return num1 > num2 ? num1 : num2;
//}
//template <typename vectype>
//vectype max1(const vector<vectype> &vec)
//{
//	return *max_element(vec.begin(), vec.end());
//}
//template <typename arrayType>
//arrayType max1(const arrayType *parray, int size)
//{
//	return *max_element(parray, parray + size);
//}
//void main()
//{
//	int iarray[] = { 1, 100, 89, 66, 578 };
//	vector <int> ivec(iarray, iarray + 5);			//vector的另一种初始化形式
//	float farray[] = { 1.5, 100.5, 89.5, 66.5, 578.5 };
//	vector <float> fvec(farray, farray + 5);
//	int imax = max1((max1(ivec)), max1(iarray,5));
//	float fmax = max1((max1(fvec)), max1(farray,5));		//此处使用函数名max会出错，会有多个max函数列表一致的max函数，原因尚不清楚
//	cout << imax<<endl;
//	cout << fmax << endl;
//}

#include<iostream>
#include<vector>

using namespace std;

const vector<int> *fibon_seq(int size)
{
	static vector <int>elem;
	for (int ix = elem.size(); ix < size;ix++)
		if (ix == 0 || ix == 1)
			elem.push_back(1);
		else
			elem.push_back(elem[ix - 1] + elem[ix - 2]);
	return &elem;
}

bool seq_elem(int pos, int &elem, const vector <int>(*seq_ptr)(int))
{
	const vector <int> *pseq = seq_ptr(pos);
	if (!pseq)
	{
		elem = 0; return false;
	}
	elem = (*pseq)[pos - 1];
	return true;
}
void main ()
{

	seq_elem()
}