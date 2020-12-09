#include "../include/lab_logic/LabLogic.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

std::shared_ptr<Matrix> readInput(std::string path) {
	auto readed = std::make_shared<std::vector<MathVector>>();
	std::ifstream fis(path);
	if (fis.is_open()) {
		std::string line;
		auto mathVec = std::make_shared<MathVector>();
		while (std::getline(fis, line)) {
			for (int i = 0; i < line.size(); ++i) {
				if (line.at(i) != ' ') {
					mathVec->push_back(strtod(&line.at(i), nullptr));
				}
			}
			readed->push_back(*mathVec);
			mathVec = std::make_shared<MathVector>();
		}
	}
	return std::make_shared<Matrix>(readed);
}

void coutVector(MathVector& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << std::setw(10)
			      << std::showpoint
			      << std::setprecision(3)
			      << std::left
			      << vec.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
}

void coutMatrix(Matrix& matrix) {
	for (int i = 0; i < matrix.getRowsSize(); ++i) {
		for (int j = 0; j < matrix.at(i).size(); ++j) {
			std::cout << std::setw(10)
				      << std::showpoint
				      << std::setprecision(3)
				      << std::right
				      << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
}

int main() {
	SetConsoleOutputCP(1251);
	std::string FILE_PATH = 
		"E:\\my_programms\\c++\\education\\LABS\\machine_learning\\expert_method\\input.txt";
	auto matr = readInput(FILE_PATH);
	LabLogic labLogic = LabLogic(matr);
	labLogic.calculate();
    std::cout << "Матрица индивидуальных весов" << std::endl;
	coutMatrix(*labLogic.getIndividualWeights());
	
	std::cout << "Матрица нормализованных индивидуальных весов" << std::endl;
	coutMatrix(*labLogic.getNormalizedWeights());
	
	std::cout << "Вектор-центроид" << std::endl;
	coutVector(*labLogic.getCentroid());
	
	std::cout << "Вектор компетенции" << std::endl;
	coutVector(*labLogic.getCompetence());
	
	std::cout << std::endl;
	std::cout << "Коэффициент конкордации: " 
		      << labLogic.getConcordanceCoefficient() 
		      << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "Матрица корреляции Спирмена" << std::endl;
	coutMatrix(*labLogic.getSpearmanCorrelation());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Коэффициент alpha: ";
	std::cout << labLogic.getSignificance() << std::endl;
	std::cout << std::endl;

	std::cout << "Число степеней свободы k: "
		      << matr->getRowsSize() - 1
		      << std::endl;
	return 0;
}
