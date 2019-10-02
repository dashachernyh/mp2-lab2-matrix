#include <string.h>
#include <iostream>
using namespace std;
#include"Exception.h"
Exception::Exception(int _Line, const char* _File, const char* _Function, const char* _Descr)
{
	Line = _Line;
	File = new char[strlen(_File) + 1];
	strcpy_s(File, strlen(_File) + 1, _File);
	Function = new char[strlen(_Function) + 1];
	strcpy_s(Function, strlen(_Function) + 1, _Function);
	Descr = new char[strlen(_Descr) + 1];
	strcpy_s(Descr, strlen(_Descr) + 1, _Descr);
}
Exception::Exception(const Exception &e)
{
	Line = e.Line;
	File = new char[strlen(e.File) + 1];
	strcpy_s(File, strlen(e.File) + 1, e.File);
	Function = new char[strlen(e.Function) + 1];
	strcpy_s(Function, strlen(e.Function) + 1, e.Function);
	Descr = new char[strlen(e.Descr) + 1];
	strcpy_s(Descr, strlen(e.Descr) + 1, e.Descr);
}

ostream& operator <<(ostream& os, Exception &e)
{
	os << "Line:  " << e.Line << endl << "File:  " << e.File << endl << "Function:  " << e.Function << endl << e.Descr;
	return os;
}
