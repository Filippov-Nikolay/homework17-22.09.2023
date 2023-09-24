#pragma once
#include <iostream>

using namespace std;

class A {
	int** arr;
	int row;
	int column;
public:
	A();
	A(int, int);
	A(const A&);
	~A();
	// ����������� ��������
	A(A&&);
	A& operator=(A&& obj);


	A& operator=(int a);

	// ���������
	// �������
	void SetArr(int**);
	void SetRow(int);
	void SetColumn(int);

	// �������
	int** GetArr() const;
	int GetRow() const;
	int GetColumn() const;
};

// ���������� �����-������
ostream& operator<<(ostream&, const A&);
istream& operator>>(istream&, A&);

// ���������� �������������� ��������
A operator+(const A, const int); // ���������� +
A operator+(const int, const A);
A operator+(const A, const A);

A operator-(const A, const int); // ���������� -
A operator-(const int, const A);
A operator-(const A, const A);

A operator*(const A, const int); // ���������� *
A operator*(const int, const A);
A operator*(const A, const A);

A operator/(const A, const int); // ���������� /
A operator/(const int, const A);
A operator/(const A, const A);

