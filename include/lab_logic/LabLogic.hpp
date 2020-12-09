#ifndef LAB_LOGIC
#define LAB_LOGIC

#include "../expert_method/weights/WeightsStorage.hpp"
#include "../expert_method/weights/WeightsService.hpp"
#include "../expert_method/competence/CompetenceResolver.hpp"
#include "../expert_method/analyzation/AnalysingCoeffsResolver.hpp"

class LabLogic {
private:
	/**INPUT*/
	std::shared_ptr<Matrix> initialMatrix;
	/**ANALYZATION*/
	std::shared_ptr<AnalysingCoeffsResolver> analysResolver;
	double concordanceCoeff;
	std::shared_ptr<Matrix> spearmanCorrel;
	/**COMPETENCE*/
	std::shared_ptr<CompetenceResolver> competResolver;
	/**WEIGHTS*/
	std::shared_ptr<WeightsService> weightsService;
	std::shared_ptr<WeightsStorage> weightsStorage;
	/**ALPHA */
	double significance;
public:
	LabLogic();
	LabLogic(std::shared_ptr<Matrix> input);
	~LabLogic();
	void setInitialMatrix(std::shared_ptr<Matrix> initialMatrix);
	void calculate();
	double getConcordanceCoefficient();
	double getSignificance();
	std::shared_ptr<Matrix> getSpearmanCorrelation();
	std::shared_ptr<MathVector> getCompetence();
	std::shared_ptr<Matrix> getIndividualWeights();
	std::shared_ptr<Matrix> getNormalizedWeights();
	std::shared_ptr<MathVector> getCentroid();
};

#endif