#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1("Hello");
	obj1.Print();
	cout << obj1.MyChr('e') << endl;


	MyString obj2(obj1);
	obj2.Print();

	obj2.Input();
	obj2.Print();
	cout << obj1.MyStrCmp(obj2) << endl;
	obj1.MyStrcpy(obj2);
	obj1.Print();

	MyString obj3("World");
	obj2.MyStrCat(obj3);
	obj2.Print();
	obj3.MyDelChr('o');
	obj3.Print();
	cout << obj3.MyStrStr("o") << endl;
}