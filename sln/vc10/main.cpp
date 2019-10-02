#include<iostream>
#include"utmatrix.h"
#include"Exception.h"
#include<conio.h>

using namespace std;

int main()
{
	try {
		TMatrix<double> matr1(2), matr2(2);
		TMatrix<double>matr3, matr4(matr1);
		cout << "enter matrix elements (size 2*2)" << endl;
		cin >> matr1 >> matr2;
		matr3 = matr1 + matr2;
		cout << "matr1+matr2=" << matr3 << endl;
		matr3 = matr1 - matr2;
		cout << "matr1-matr2=" << matr3 << endl;
		/*
		TVector<double>a, b(5), c(5), r(5);
		double m[] = { 1,2,3,4 };
		TVector<double> s(m, 4,0);
		double i = 3, n = 2, p = 6;
		cout << "enter vector elements (size=5)" << endl;
		cin >> b >> c;
		cout <<"b= "<< b << endl <<"c= "<< c << endl;
		p = b * c;
		cout <<"b*c= "<< p << endl;
		a = b;
		cout <<"a=b= "<< a << endl;
		r = i * b;
		cout <<i <<"*b= "<< r << endl;
		a = a / n;
		cout <<"a/"<<n<<"= "<< a << endl;
		//cout << s << endl;
		++r;
		cout <<"++r= "<< r << endl;
		r = c * n;
		cout <<"c*"<<n<<"= "<< r << endl;*/

		/*TVector<double> a(-2);
		TVector<double> b(3), c(3),p(3);
		double t = 0;
		cin >> b >> c;
		cout << b << endl << c << endl;
		b = b / t;*/
	}
	catch (Exception ex)
	{
		cout << ex;
	}

	_getch();
}