#include "../include/mathematic/structures/Matrix.hpp"
#include <iostream>

void coutVector(MathVector& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
}

void coutMatrix(Matrix& matrix) {
	for (int i = 0; i < matrix.getRowsSize(); ++i) {
		for (int j = 0; j < matrix.at(i).size(); ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
}

int main() {
	return 0;
}