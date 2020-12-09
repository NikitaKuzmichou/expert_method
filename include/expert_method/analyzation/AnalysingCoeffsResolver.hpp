#ifndef CONCORDANCE_FACTOR_RESOLVER
#define CONCORDANCE_FACTOR_RESOLVER

#include "../../mathematic/structures/Matrix.hpp"
#include "../../mathematic/service/MathVectorService.hpp"

class AnalysingCoeffsResolver {
private:
    std::shared_ptr<MathVectorService> vecService;
public:
    AnalysingCoeffsResolver();
    double getConcordanceCoefficient(std::shared_ptr<Matrix> matrix);
    double getSignificance(double concordance, Matrix& matrix);
    std::shared_ptr<Matrix> getSpearmanCorrelation(std::shared_ptr<Matrix> matrix);
private:
    double getSummSquaresDeviations(Matrix& matrix);
};

#endif