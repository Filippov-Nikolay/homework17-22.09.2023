#pragma once

template <class A>
class Matrix {
	A* arr;
	int row;
	int column;
public:
	// ������������ / ����������
	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(const Matrix<A>&);
	~Matrix();
	// ����������� ��������
	Matrix(Matrix<A>&&);
	Matrix<A>& operator=(Matrix<A>&& obj);

	
	void Input(); // ���� � ����������
	void Init(); // ���������� ����. �������
	void Print(); // �����

	
	int SearchMax(); // ����� ����. ��������
	int SearchMin(); // ����� ���. ��������


	// ���������
	// �������
	void SetArr(A*);
	void SetRow(int);
	void SetColumn(int);

	// �������
	A* GetArr();
	int GetRow();
	int GetColumn();


	// ���������� �������������� ��������
	Matrix<A> operator+(const Matrix<A>, const int); // ���������� +
	Matrix<A> operator+(const int, const Matrix<A>);

	Matrix<A> operator-(const Matrix<A>, const int); // ���������� -
	Matrix<A> operator-(const int, const Matrix<A>);

	Matrix<A> operator*(const Matrix<A>, const int); // ���������� *
	Matrix<A> operator*(const int, const Matrix<A>);

	Matrix<A> operator/(const Matrix<A>, const int); // ���������� /
	Matrix<A> operator/(const int, const Matrix<A>);
};


// ������������ / ����������
template<class A>
inline Matrix<A>::Matrix() {
}

template<class A>
inline Matrix<A>::Matrix(int) {
}

template<class A>
inline Matrix<A>::Matrix(int, int) {
}

template<class A>
inline Matrix<A>::Matrix(const Matrix<A>&) {
}

template<class A>
inline Matrix<A>::~Matrix() {
}

// ����������� ��������
template<class A>
inline Matrix<A>::Matrix(Matrix<A>&&) {
}

template<class A>
inline Matrix<A>& Matrix<A>::operator=(Matrix<A>&& obj) {
	// TODO: �������� ����� �������� return
}


template<class A>
inline void Matrix<A>::Input() {

}

template<class A>
inline void Matrix<A>::Init() {

}

template<class A>
inline void Matrix<A>::Print() {

}


template<class A>
inline int Matrix<A>::SearchMax() {
	return 0;
}

template<class A>
inline int Matrix<A>::SearchMin() {
	return 0;
}


template<class A>
inline void Matrix<A>::SetArr(A*) {
}

template<class A>
inline void Matrix<A>::SetRow(int) {
}

template<class A>
inline void Matrix<A>::SetColumn(int) {
}


template<class A>
inline A* Matrix<A>::GetArr() {
	return nullptr;
}

template<class A>
inline int Matrix<A>::GetRow() {
	return 0;
}

template<class A>
inline int Matrix<A>::GetColumn() {
	return 0;
}