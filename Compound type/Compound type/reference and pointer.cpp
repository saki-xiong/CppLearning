#include<iostream>

//引用的实验，引进即别名，不能定义引用的引用，引用必须初始化
void main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	//r2 = 3.14159;  //正确，输出0 0 3.14159 3.14159
	//r2 = r1;       //输出0 0 0 0
	//i = r2;        //强制转换类型，输出0 0 0 0
	//r1 = d;        //强制转换类型，输出0 0 0 0
	std::cout << i << "  " << r1 << "  " << d << "  " << r2 << std::endl;
}
