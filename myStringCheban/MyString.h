#pragma once
#include <iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
	static int quantity;
public:
	MyString();
	MyString(const char* obj);
	MyString(const MyString& obj);
	void Print();
	void Input();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	static void QuantityOfObjects();
	char operator[](int index);
	char* GetStr();
	void SetStr(const char* s);
	~MyString();
};