#include "../../include/expert_method/weights/WeightsService.hpp"

WeightsService::WeightsService() {
	this->vecService = std::make_shared<MathVectorService>();
}

std::shared_ptr<Matrix> WeightsService::getIndividualWeights(Matrix& matrix) {
	auto individualWeights = std::make_shared<Matrix>(
		                     matrix.getRowsSize(), matrix.getColsSize());
	for (int i = 0; i < matrix.getRowsSize(); ++i) {
		for (int j = 0; j < matrix.getColsSize(); ++j) {
			individualWeights->at(i).at(j) = matrix.getRowsSize() - matrix.at(i).at(j);
		}
	}
	return individualWeights;
}

std::shared_ptr<Matrix> WeightsService::getNormalizedWeights(Matrix& matrix) {
	size_t n = matrix.getRowsSize();
	return std::make_shared<Matrix>((2.0 / (n * (n - 1))) * matrix);
}

std::shared_ptr<MathVector> WeightsService::getCentroid(Matrix& matrix) {
	auto centroid = std::make_shared<MathVector>(matrix.getRowsSize());
	for (int i = 0; i < matrix.getRowsSize(); ++i) {
		centroid->at(i) = this->vecService->getVectorSumm(matrix.at(i)) / matrix.getColsSize();
	}
	return centroid;
}