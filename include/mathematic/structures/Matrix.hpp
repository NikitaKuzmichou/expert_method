#ifndef MATRIX
#define MATRIX

#include "MathVector.hpp"

class Matrix {
private:
	std::shared_ptr<std::vector<MathVector>> matrix;
public:
	Matrix();
	Matrix(size_t rows);
	Matrix(size_t rows, size_t cols);
	~Matrix();
	size_t getRowsSize() const;
	size_t getColsSize() const;
	void setSize(size_t rows, size_t cols);
	MathVector& at(int i);
	MathVector& operator[] (int i);
	Matrix& operator= (Matrix& right);
	friend Matrix operator+ (Matrix& matr1, Matrix& matr2);
	friend Matrix operator- (Matrix& matr1, Matrix& matr2);
	friend Matrix operator* (Matrix& matr1, Matrix& matr2);
	friend MathVector operator* (Matrix& matr, MathVector& vec);
	friend Matrix operator* (Matrix& matr, double scalar);
	friend Matrix operator* (double scalar, Matrix& matr);
	friend Matrix operator/ (Matrix& matr, double scalar);
private:
	void initRows(size_t rows);
};

#endif // !Matrix
