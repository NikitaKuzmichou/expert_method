#include "../../include/mathematic/structures/Matrix.hpp"
#include "../../include/mathematic/exceptions/MatrixSize.hpp"

Matrix::Matrix() {
	this->matrix = std::make_shared<std::vector<MathVector>>();
}

Matrix::Matrix(size_t rows) {
	this->matrix = std::make_shared<std::vector<MathVector>>(rows);
}

Matrix::Matrix(size_t rows, size_t cols) {
	this->setSize(rows, cols);
}

Matrix::~Matrix() {
	this->matrix.reset();
}

size_t Matrix::getRowsSize() const {
	return this->matrix->size();
}

size_t Matrix::getColsSize() const {
	return this->matrix->front().size();
}

void Matrix::setSize(size_t rows, size_t cols) {
	this->matrix = std::make_shared<std::vector<MathVector>>(rows);
	for (int i = 0; i < rows; ++i) {
		this->matrix->at(i) = *(std::make_shared<MathVector>(cols));
	}
}

MathVector& Matrix::at(int i) {
	return this->matrix->at(i);
}

MathVector& Matrix::operator[] (int i) {
	return this->at(i);
}

Matrix& Matrix::operator= (Matrix& right) {
	if (this == &right) {
		return *this;
	}
	this->matrix->resize(right.getRowsSize(), right.getColsSize());
	for (int i = 0; i < right.getRowsSize(); ++i) {
		this->matrix->at(i) = right.at(i);
	}
	return *this;
}

Matrix operator+ (Matrix& matr1, Matrix& matr2) {
	if (matr1.getRowsSize() != matr2.getRowsSize() ||
		matr1.getColsSize() != matr2.getColsSize()) {
		throw MatrixSizeException();
	}
	Matrix matrix = Matrix(matr1.getRowsSize(), matr1.getColsSize());
	for (int i = 0; i < matr1.getRowsSize(); ++i) {
		matrix.at(i) = matr1.at(i) + matr2.at(i);
	}
	return matrix;
}

Matrix operator- (Matrix& matr1, Matrix& matr2) {
	if (matr1.getRowsSize() != matr2.getRowsSize() ||
		matr1.getColsSize() != matr2.getColsSize()) {
		throw MatrixSizeException();
	}
	Matrix matrix = Matrix(matr1.getRowsSize(), matr1.getColsSize());
	for (int i = 0; i < matr1.getRowsSize(); ++i) {
		matrix.at(i) = matr1.at(i) - matr2.at(i);
	}
	return matrix;
}

Matrix operator* (Matrix& matr1, Matrix& matr2) {
	if (matr1.getColsSize() != matr2.getRowsSize()) {
		throw MatrixSizeException("First matrix number of \
                                   columns not equal second \
                                   matrix number of rows");
	}
	Matrix result = Matrix(matr1.getRowsSize(), matr2.getColsSize());
	for (int i = 0; i < matr1.getRowsSize(); ++i) {
		for (int j = 0; j < matr2.getColsSize(); ++j) {
			for (int k = 0; k < matr1.getColsSize(); ++k) {
				result.at(i).at(j) += matr1.at(i).at(k) * matr2.at(k).at(j);
			}
		}
	}
	return result;
}

MathVector operator* (Matrix& matr, MathVector& vec) {
	if (matr.getColsSize() != vec.size()) {
		throw MatrixSizeException("Matrix number of \
                                   columns not equal vector\
                                   number of rows");
	}
	MathVector result = MathVector(vec.size());
	for (int i = 0; i < matr.getRowsSize(); ++i) {
		for (int j = 0; j < vec.size(); ++j) {
			result.at(i) += matr.at(i).at(j) * vec.at(i);
		}
	}
	return result;
}

Matrix operator* (Matrix& matr, double scalar) {
	Matrix matrix = Matrix(matr.getRowsSize(), matr.getColsSize());
	for (int i = 0; i < matr.getRowsSize(); ++i) {
		matrix.at(i) = matr.at(i) * scalar;
	}
	return matrix;
}

Matrix operator* (double scalar, Matrix& matr) {
	return matr * scalar;
}

Matrix operator/ (Matrix& matr, double scalar) {
	return matr * (1.0 / scalar);
}
