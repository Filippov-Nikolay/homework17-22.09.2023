#pragma once
#include <iostream>

// row - ������
// column - �������

using namespace std;

template <class T>
class Matrix {
	T** arr;
	int row;
	int column;
public:
	// ������������ / ����������
	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(const Matrix<T>&); // ����������� �����������
	~Matrix();
	// ����������� ��������
	Matrix(Matrix<T>&&);
	Matrix<T>& operator=(Matrix<T>&& obj);


	void Input(); // ���� � ����������
	void Init(); // ���������� ����. �������
	void Print(); // �����


	int SearchMax(); // ����� ����. ��������
	int SearchMin(); // ����� ���. ��������


	// ���������
	// �������
	void SetArr(T*);
	void SetRow(int);
	void SetColumn(int);

	// �������
	T** GetArr();
	int GetRow();
	int GetColumn();
};

// ������������ / ����������
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
	row = r;
	column = c;

	arr = new T * [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = 0;
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

// ����������� ��������
template<class T>
inline Matrix<T>::Matrix(Matrix<T>&& obj) {
	row = obj.row;
	obj.row = 0;

	column = obj.column;
	obj.column = 0;

	arr = new T[obj.row];

	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; i < obj.column; j++)
			arr[i] = obj.arr[i][j];
	}

	for (int i = 0; i < obj.row; i++) {
		arr[i] = new T[obj.column];
		obj.arr[i] = nullptr;
	}
}
template<class T>
inline Matrix<T>& Matrix<T>::operator=(Matrix<T>&& obj) {
	row = obj.row;
	obj.row = 0;

	column = obj.column;
	obj.column = 0;

	arr = new T[obj.row];

	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; i < obj.column; j++)
			arr[i] = obj.arr[i][j];
	}

	for (int i = 0; i < obj.row; i++) {
		arr[i] = new T[obj.column];
		obj.arr[i] = nullptr;
	}
}


// ���� � ����������
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
// ���������� ����. �������
template<class T>
inline void Matrix<T>::Init() {
	arr = new T* [row];

	for (int i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = rand() % 50;
}
// �����
template<class T>
inline void Matrix<T>::Print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}


template<class T>
inline int Matrix<T>::SearchMax() {
	return 0;
}

template<class T>
inline int Matrix<T>::SearchMin() {
	return 0;
}


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


template<class T>
inline T** Matrix<T>::GetArr() {
	return arr;
}
template<class T>
inline int Matrix<T>::GetRow() {
	return row;
}
template<class T>
inline int Matrix<T>::GetColumn() {
	return column;
}