#include<iostream>

//���õ�ʵ�飬���������������ܶ������õ����ã����ñ����ʼ��
void main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	//r2 = 3.14159;  //��ȷ�����0 0 3.14159 3.14159
	//r2 = r1;       //���0 0 0 0
	//i = r2;        //ǿ��ת�����ͣ����0 0 0 0
	//r1 = d;        //ǿ��ת�����ͣ����0 0 0 0
	std::cout << i << "  " << r1 << "  " << d << "  " << r2 << std::endl;
}