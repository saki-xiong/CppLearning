//++   @   ��  ��   ::   #   ""   &   ( )   {  }    <  >    <<   >>    *   

#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cin; 
using std::cout;
using std::endl;


void main()
{ 
	vector <string> s;
	string s1;
	//int i;
	cout << "Enter letters(Ctrl+z to end):" << endl; 

	while (cin >> s1)
		s.push_back(s1);

	/*for (auto &c : s)
		c = toupper(c);

	for (i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}*/

	for (vector<string>::size_type i = 0; i < s.size(); ++i)
	{
		for (string::size_type j = 0; j < s[i].size(); ++j)
		{
			if (islower(s[i][j]))
				s[i][j] = toupper(s[i][j]);
		}
	cout << s[i] << " " << endl;
	}

}

//�˽�vector��Ԫ����ӣ����±��ȡָ��Ԫ�أ��Լ����������
//void main()
//{
//	int i; int grade;
//	vector <int> score;
//	vector <int> level(11, 0); 
//	cout << "Enter numbers(Ctrl+z to end):" << endl;
//	while (cin >> grade)
//	{
//		if (grade <= 100)
//		{
//			++level[grade / 10];
//			score.push_back(grade);
//		}
//	}
//	for (i = 0; i < level.size(); i++)
//	{
//		//cout << i << "   " << score[i] << "   " << level[i] << endl; //���score����  �ᵼ���±����
//		cout << i << "   "<< level[i] << endl;
//	}
//}    

