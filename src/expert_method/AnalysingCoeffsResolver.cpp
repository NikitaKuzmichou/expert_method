#include "../../include/expert_method/analyzation/AnalysingCoeffsResolver.hpp"

AnalysingCoeffsResolver::AnalysingCoeffsResolver() {
    this->vecService = std::make_shared<MathVectorService>();
}

std::shared_ptr<Matrix> AnalysingCoeffsResolver::getSpearmanCorrelation(
                                                     std::shared_ptr<Matrix> matrix) {
    auto correlation = std::make_shared<Matrix>(matrix->getColsSize(),
                                                matrix->getColsSize());
    for (int j = 0; j < matrix->getColsSize(); j++) {
        for (int k = 0; k < matrix->getColsSize(); k++) {
            double squaresSumm = 0;
            for (int i = 0; i < matrix->getRowsSize(); i++) {
                double tmp = matrix->at(i).at(j) - matrix->at(i).at(k);
                squaresSumm += tmp * tmp;
            }
            squaresSumm *= 6.0 / (matrix->getRowsSize() * 
                          (matrix->getRowsSize() * matrix->getRowsSize() - 1));
            correlation->at(j).at(k) = 1 - squaresSumm;
        }
    }
    return correlation;
}

double AnalysingCoeffsResolver::getConcordanceCoefficient(std::shared_ptr<Matrix> matrix) {
    size_t factors = matrix->getRowsSize();
    size_t experts = matrix->getColsSize();
    double concordance = 12.0 * this->getSummSquaresDeviations(*matrix);
    concordance /= experts * experts * factors * (factors * factors - 1.0);
    return concordance;
}

double AnalysingCoeffsResolver::getSummSquaresDeviations(Matrix& matrix) {
    auto expertsSumm = std::make_shared<MathVector>(matrix.getRowsSize());
    for (int i = 0; i < matrix.getRowsSize(); ++i) {
        expertsSumm->at(i) = this->vecService->getVectorSumm(matrix.at(i));
    }
    double averageExpertsSumm = (matrix.getColsSize() * (matrix.getRowsSize() + 1.0)) / 2.0;
    double squaresDeviations = 0;
    for (int i = 0; i < matrix.getRowsSize(); ++i) {
        double tmp = expertsSumm->at(i) - averageExpertsSumm;
        squaresDeviations += tmp * tmp;
    }
    return squaresDeviations;
}

double AnalysingCoeffsResolver::getSignificance(double concordance, Matrix& matrix) {
    return matrix.getColsSize() * (matrix.getRowsSize() - 1) * concordance;
}
