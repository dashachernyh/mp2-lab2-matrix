#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class Exception
{
	int Line;
	char* File;
	char* Function;
	char* Descr;
public:
	Exception(int _Line, const char* _File, const char* _Function, const char* _Descr);
	Exception(const Exception &e);
	~Exception()
	{
		delete[]File;
		delete[]Function;
		delete[]Descr;
	}
	friend ostream& operator <<(ostream & os, Exception &e);
};