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
	// Конструктор переноса
	A(A&&);
	A& operator=(A&& obj);


	A& operator=(int a);

	// Аксессоры
	// Сеттеры
	void SetArr(int**);
	void SetRow(int);
	void SetColumn(int);

	// Геттеры
	int** GetArr() const;
	int GetRow() const;
	int GetColumn() const;
};

// Перегрузка ввода-вывода
ostream& operator<<(ostream&, const A&);
istream& operator>>(istream&, A&);

// Перегрузки арифметических операций
A operator+(const A, const int); // Перегрузка +
A operator+(const int, const A);
A operator+(const A, const A);

A operator-(const A, const int); // Перегрузка -
A operator-(const int, const A);
A operator-(const A, const A);

A operator*(const A, const int); // Перегрузка *
A operator*(const int, const A);
A operator*(const A, const A);

A operator/(const A, const int); // Перегрузка /
A operator/(const int, const A);
A operator/(const A, const A);

