#pragma once

template <class A>
class Matrix {
	A* arr;
	int row;
	int column;
public:
	// Консутркторы / Деструктор
	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(const Matrix<A>&);
	~Matrix();
	// Конструктор переноса
	Matrix(Matrix<A>&&);
	Matrix<A>& operator=(Matrix<A>&& obj);

	
	void Input(); // Ввод с клавиатуры
	void Init(); // Заполнение случ. числами
	void Print(); // Вывод

	
	int SearchMax(); // Поиск макс. элемента
	int SearchMin(); // Поиск мин. элемента


	// Аксессоры
	// Сеттеры
	void SetArr(A*);
	void SetRow(int);
	void SetColumn(int);

	// Геттеры
	A* GetArr();
	int GetRow();
	int GetColumn();


	// Перегрузки арифметических операций
	Matrix<A> operator+(const Matrix<A>, const int); // Перегрузка +
	Matrix<A> operator+(const int, const Matrix<A>);

	Matrix<A> operator-(const Matrix<A>, const int); // Перегрузка -
	Matrix<A> operator-(const int, const Matrix<A>);

	Matrix<A> operator*(const Matrix<A>, const int); // Перегрузка *
	Matrix<A> operator*(const int, const Matrix<A>);

	Matrix<A> operator/(const Matrix<A>, const int); // Перегрузка /
	Matrix<A> operator/(const int, const Matrix<A>);
};


// Консутркторы / Деструктор
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

// Конструктор переноса
template<class A>
inline Matrix<A>::Matrix(Matrix<A>&&) {
}

template<class A>
inline Matrix<A>& Matrix<A>::operator=(Matrix<A>&& obj) {
	// TODO: вставьте здесь оператор return
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