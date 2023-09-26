#pragma once
#include <iostream>

// row - строка
// column - колонка

using namespace std;

template <class T = int>
class Matrix {
	T** arr;
	int row;
	int column;
public:
	// Консутркторы / Деструктор
	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(const Matrix<T>&); // Конструктор копирования
	~Matrix();
	// Конструктор переноса
	Matrix(Matrix<T>&&);
	Matrix<T>& operator=(Matrix<T>&& obj);


	void Input(); // Ввод с клавиатуры
	void Init(); // Заполнение случ. числами
	void Print() const; // Вывод
	void PrintIndex(int, int) const; // Вывод по индексу


	void SearchMax(int&, int&); // Поиск макс. элемента
	void SearchMin(int&, int&); // Поиск мин. элемента


	// Аксессоры
	// Сеттеры
	void SetArr(T*);
	void SetRow(int);
	void SetColumn(int);

	// Геттеры
	T** GetArr() const;
	int GetRow() const;
	int GetColumn() const;


	// Перегрузки арифметических операций
	Matrix<T> operator+(const Matrix<T>& obj); // Перегрузка +
	Matrix<T> operator-(const Matrix<T>& obj); // Перегрузка -
	Matrix<T> operator*(const Matrix<T>& obj); // Перегрузка *
	Matrix<T> operator/(const Matrix<T>& obj); // Перегрузка /
	Matrix<T> operator+(const int& number); // Перегрузка +
	Matrix<T> operator-(const int& number); // Перегрузка -
	Matrix<T> operator*(const int& number); // Перегрузка *
	Matrix<T> operator/(const int& number); // Перегрузка /
};

template <class T>
Matrix<T> operator+(const int number, const Matrix<T>& obj);
template <class T>
Matrix<T> operator-(const int number, const Matrix<T>& obj);
template <class T>
Matrix<T> operator*(const int number, const Matrix<T>& obj);
template <class T>
Matrix<T> operator/(const int number, const Matrix<T>& obj);

// Консутркторы / Деструктор
template<class T>
inline Matrix<T>::Matrix() {
	row = 0;
	column = 0;
	arr = nullptr;
}
template<class T>
inline Matrix<T>::Matrix(int c) {
	column = c;
}
template<class T>
inline Matrix<T>::Matrix(int r, int c) {
	if (r <= 0 || c <= 0) {
		cout << "Вы ввели неверный размер двумерного массива!" << endl;
		r = 0;
		c = 0;
		arr = nullptr;
	}
	else {
		row = r;
		column = c;

		arr = new T * [row];

		for (int i = 0; i < row; i++)
			arr[i] = new T[column];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				arr[i][j] = 0;
	}
}
template<class T>
inline Matrix<T>::Matrix(const Matrix<T>& obj) {
	row = obj.row;
	column = obj.column;
	arr = new T* [obj.row];

	for (int i = 0; i < obj.row; i++)
		arr[i] = new T[obj.column];

	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; i < obj.column; j++)
			arr[i][j] = obj.arr[i][j];
	}
}
template<class T>
inline Matrix<T>::~Matrix() {
	if (arr != nullptr) {
		for (int i = 0; i < row; i++)
			delete[] arr[i];
		delete[] arr;
	}
}
// Конструктор переноса
template<class T>
inline Matrix<T>::Matrix(Matrix<T>&& obj) {
	row = obj.row;
	obj.row = 0;

	column = obj.column;
	obj.column = 0;

	arr = new T * [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			arr[i][j] = obj.arr[i][j];
			obj.arr[i][j] = 0;
		}	
}
template<class T>
inline Matrix<T>& Matrix<T>::operator=(Matrix<T>&& obj) {
	row = obj.row;
	obj.row = 0;

	column = obj.column;
	obj.column = 0;

	arr = new T * [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			arr[i][j] = obj.arr[i][j];
			obj.arr[i][j] = 0;
		}
	return *this;
}


// Ввод с клавиатуры
template<class T>
inline void Matrix<T>::Input() {
	arr = new T * [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			cout << "[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
}
// Заполнение случ. числами
template<class T>
inline void Matrix<T>::Init() {
	arr = new T* [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = rand() % 50;
}
// Вывод
template<class T>
inline void Matrix<T>::Print() const {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
// Вывод по индексу
template<class T>
inline void Matrix<T>::PrintIndex(int index_i, int index_j) const {
	cout << arr[index_i][index_j];
}


// Поиск макс./мин. элемента
template<class T>
inline void Matrix<T>::SearchMax(int& index_i, int& index_j) {
	index_i = 0;
	index_j = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			if (i == 0 && j == 0)
				continue;
			if (arr[index_i][index_j] < arr[i][j]) {
				index_i = i;
				index_j = j;
			}
		}
}
template<class T>
inline void Matrix<T>::SearchMin(int& index_i, int& index_j) {
	index_i = 0;
	index_j = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			if (i == 0 && j == 0)
				continue;
			if (arr[index_i][index_j] > arr[i][j]) {
				index_i = i;
				index_j = j;
			}
		}
}


// Аксессоры
// Сеттеры
template<class T>
inline void Matrix<T>::SetArr(T* a) {
	arr = a;
}
template<class T>
inline void Matrix<T>::SetRow(int r) {
	row = r;
}
template<class T>
inline void Matrix<T>::SetColumn(int c) {
	column = c;
}

// Геттеры
template<class T>
inline T** Matrix<T>::GetArr() const {
	return arr;
}
template<class T>
inline int Matrix<T>::GetRow() const {
	return row;
}
template<class T>
inline int Matrix<T>::GetColumn() const {
	return column;
}


// Перегрузки арифметических операций
template<class T> // Перегрузка +
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj) {
	Matrix<T> rez(row, column);
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] + obj.arr[i][j]);

	return rez;
}
template<class T> // Перегрузка -
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] - obj.arr[i][j]);

	return rez;
}
template<class T> // Перегрузка *
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] * obj.arr[i][j]);

	return rez;
}
template<class T> // Перегрузка /
inline Matrix<T> Matrix<T>::operator/(const Matrix<T>& obj) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] / obj.arr[i][j]);

	return rez;
}
template<class T> // Перегрузка +
inline Matrix<T> Matrix<T>::operator+(const int& number) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] + number);

	return rez;
}
template<class T> // Перегрузка -
inline Matrix<T> Matrix<T>::operator-(const int& number) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] - number);

	return rez;
}
template<class T> // Перегрузка *
inline Matrix<T> Matrix<T>::operator*(const int& number) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] * number);

	return rez;
}
template<class T> // Перегрузка /
inline Matrix<T> Matrix<T>::operator/(const int& number) {
	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			rez.arr[i][j] = (arr[i][j] / number);

	return rez;
}
template<class T> // Перегрузка +
inline Matrix<T> operator+(const int number, const Matrix<T>& obj) {
	int row = obj.GetRow();
	int column = obj.GetColumn();		

	Matrix<T> rez(row, column);			

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			*(*(rez.GetArr() + j) + i)= *(*(obj.GetArr() + j) + i) + number;
			 
	return rez;
}
template<class T> // Перегрузка -
inline Matrix<T> operator-(const int number, const Matrix<T>& obj) {
	int row = obj.GetRow();
	int column = obj.GetColumn();

	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			*(*(rez.GetArr() + j) + i) = *(*(obj.GetArr() + j) + i) - number;

	return rez;
}
template<class T> // Перегрузка *
inline Matrix<T> operator*(const int number, const Matrix<T>& obj) {
	int row = obj.GetRow();
	int column = obj.GetColumn();

	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			*(*(rez.GetArr() + j) + i) = *(*(obj.GetArr() + j) + i) * number;

	return rez;
}
template<class T> // Перегрузка /
inline Matrix<T> operator/(const int number, const Matrix<T>& obj) {
	int row = obj.GetRow();
	int column = obj.GetColumn();

	Matrix<T> rez(row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			*(*(rez.GetArr() + j) + i) = *(*(obj.GetArr() + j) + i) / number;

	return rez;
}