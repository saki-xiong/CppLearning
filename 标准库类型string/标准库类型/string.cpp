//++   @   £¿  £¡   ::   #   ""   &   ()   {}    <>    <<   >>    *   _


void main()
{
	string s2("hello");
	for (auto &c : s2)
	c = toupper(c);
	cout << s2 << endl;
}

