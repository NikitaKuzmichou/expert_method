#include "../../include/mathematic/service/MatrixService.hpp"

MatrixService::MatrixService() {
	this->vecService = std::make_shared<MathVectorService>();
}

double MatrixService::getMax(Matrix& matrix) {
	double max = this->vecService->getMax(matrix.at(0));
	for (int i = 1; i < matrix.getRowsSize(); ++i) {
		double tmp = this->vecService->getMax(matrix.at(i));
		if (max < tmp) {
			max = tmp;
		}
	}
	return max;
}

double MatrixService::getMin(Matrix& matrix) {
	double min = this->vecService->getMin(matrix.at(0));
	for (int i = 1; i < matrix.getRowsSize(); ++i) {
		double tmp = this->vecService->getMin(matrix.at(i));
		if (min < tmp) {
			min = tmp;
		}
	}
	return min;
}

Matrix MatrixService::getTransposed(Matrix& matrix) {
	Matrix matrix = Matrix(matrix.getColsSize(), matrix.getRowsSize());
	for (int i = 0; i < matrix.getRowsSize(); ++i) {
		for (int j = 0; j < matrix.getColsSize(); ++j) {
			matrix.at(j).at(i) = matrix.at(i).at(j);
		}
	}
	return matrix;
}
