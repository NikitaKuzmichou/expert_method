#ifndef COMPETENCE_RESOLVER
#define COMPETENCE_RESOLVER

#include "../../mathematic/structures/Matrix.hpp"
#include "../../mathematic/service/MatrixService.hpp"
#include "../../mathematic/service/MathVectorService.hpp"

class CompetenceResolver {
private:
	unsigned numIterations;
	std::shared_ptr<MathVector> competence;
	std::shared_ptr<MathVectorService> vecService;
	std::shared_ptr<MatrixService> matrService;
public:
	CompetenceResolver();
	CompetenceResolver(unsigned numIterations);
	CompetenceResolver(std::shared_ptr<Matrix> individualWeights);
	CompetenceResolver(unsigned numIterations, std::shared_ptr<Matrix> individualWeights);
	~CompetenceResolver();
	void setNumIterations(unsigned iterations);
	unsigned getNumIterations();
	void resolveCompetence(std::shared_ptr<Matrix> matrix);
	std::shared_ptr<MathVector> getCompetence();
private:
	void calculateInitialApproximation(size_t size);
	void calculateNextApproximation(MathVector& vecUnweightCoeffs);
};

#endif // !COMPETENCE_RESOLVER
