#include "MyString.h"
#include <iostream>
using namespace std;

int MyString::quantity = 0;

MyString::MyString()
{
	length = 80;
	str = new char[length];
	quantity++;
}

MyString::MyString(const char* obj)
{
	length = strlen(obj);
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj);
	quantity++;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	quantity++;
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::Input()
{
	char buff[80];
	cout << "Input string: ";
	cin >> buff;
	if (str != nullptr)
	{
		delete[] str;
	}
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* str)
{
	bool found = false;
	char* foundstr = strstr((*this).str, str);
	if (foundstr != nullptr)
	{
		found = true;
	}
	return found;
}

int MyString::MyChr(char c)
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			index = i;
		}
	}
	return index;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	char* buff = new char[length + 1];
	strcpy_s(buff, length + 1, str);
	delete[] str;
	str = new char[length + b.length + 1];
	strcpy_s(str, length + 1, buff);
	strcat_s(str, length + b.length + 1, b.str);
}

void MyString::MyDelChr(char c)
{
	int i = (*this).MyChr(c);
	if (i != -1)
	{
		char* buff = new char[length + 1];
		strcpy_s(buff, length + 1, str);
		delete[] str;
		str = new char[length];
		for (int j = 0, k = 0; j < length + 1; j++)
		{
			if (j != i)
			{
				str[k] = buff[j];
				k++;
			}
		}
	}
}

int MyString::MyStrCmp(MyString& b)
{
	if (length < b.length)
	{
		return -1;
	}
	else if (length > b.length)
	{
		return 1;
	}
	else {
		return 0;
	}
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::QuantityOfObjects()
{
	cout << "Quantity of object with class MyString: " << quantity << endl;
}

char MyString::operator[](int index)
{
	if (index >= 0 && index < length)
		return str[index];
	return -1;
}

char* MyString::GetStr()
{
	return str;
}

void MyString::SetStr(const char* s)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	length = strlen(s);
	str = new char[length+1];
	strcpy_s(str, length + 1, s);

}