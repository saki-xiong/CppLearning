/*essential c++ Exercise 1.4 输入两个字符串，连接输出。没有使用array或者vector
第一次调试出错，忘记使用命名空间的步骤
saki于2015 0906 1910
*/
using namespace std;
#include<iostream>
#include<string>
#include<vector>


//void main()
//{
//	string first_name, last_name;
//	cout << "enter your firt name:" << endl;
//	cin >> first_name;
//	cout << "enter your last name:" << endl;
//	cin >> last_name;
//	cout << first_name << ' ' << last_name;
//}

/*E1.6 array vector的使用
	saki 2015 0906 1944
*/

/*using array*/
//void main()
//{
//	const int array_size = 128;
//	int a[array_size];
//	int num, sub=0,sum=0;
//	while (cin >> num && sub < array_size)
//		a[sub++] = num;
//	for (int i = 0; i < sub; i++)
//		sum = sum + a[i];
//	int average = sum / (sub);
//	cout <<"sum:"<< sum << ',' <<"average:"<< average << endl;
//}

/*using vector*/
//void main()
//{
//	vector<int> a;
//	int num;
//	while (cin >> num)
//		a.push_back(num);						//vector中元素的添加
//	int	sum = 0;
//	for (int i = 0; i < a.size(); i++)			//vector的size
//		sum += a[i];							//vector的元素取用
//	int average = sum /a.size();
//	cout << "sum:" << sum << ',' << "average:" << average << endl;
//}

/*E1.7 文件的读写操作*/

//#include<fstream>
//#include<string>
//#include<algorithm>
//
//void main()
//{
//	ifstream infile("C:\\Users\\Administrator\\Desktop\\test data.txt");
//	if (! infile)
//		cerr << "unable to open input file" << endl;
//	ofstream outfile("C:\\Users\\Administrator\\Desktop\\sort data.txt");
//	if (! outfile)
//		cerr << "unable to open output file" << endl;
//	vector<string> text;
//	string word;
//	while (infile >> word)
//		text.push_back(word);
//	for (int ix = 0; ix < text.size(); ix++)
//		cout << text[ix]<<' ';
//	cout << endl;
//	sort(text.begin(), text.end());
//	for (int ix = 0; ix < text.size(); ix++)
//		outfile << text[ix]<<' ';
//}

