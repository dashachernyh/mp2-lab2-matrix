// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
using namespace std;
#include "utmatrix.h"
#include <conio.h>
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j,k=3;
  bool bo;
  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
 /* c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  c = b - a;
  cout << "Matrix c = a - b" << endl << c << endl;
  c=k*b;
  cout << "Matrix c = 3* b" << endl << c << endl;
 /* c = b / k;
  cout << "Matrix c = b/3" << endl << c << endl;*/
  bo = (a == b);
  cout << "a==b" << ' ' << bo << endl;
  _getch();
}
//---------------------------------------------------------------------------
