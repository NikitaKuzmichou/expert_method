#include "../include/mathematic/structures/Matrix.hpp"
#include "../include/expert_method/weights/WeightsService.hpp"
#include "../include/mathematic/service/MatrixService.hpp"
#include "../include/expert_method/competence/CompetenceResolver.hpp"
#include <iostream>

void coutVector(MathVector& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec.at(i) << std::endl;
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
	auto matr = std::make_shared<Matrix>(2, 3);
	(*matr)[0][0] = 0.8;
	(*matr)[0][1] = 0.4;
	(*matr)[0][2] = 0.7;
	(*matr)[1][0] = 0.2;
	(*matr)[1][1] = 0.6;
	(*matr)[1][2] = 0.3;
	CompetenceResolver resolver = CompetenceResolver(1);
	resolver.resolveCompetence(matr);
	coutVector(*resolver.getCompetence());
	return 0;
}