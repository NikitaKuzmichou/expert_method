#include "../../include/lab_logic/LabLogic.hpp"

LabLogic::LabLogic() {
	this->analysResolver = std::make_shared<AnalysingCoeffsResolver>();
	this->competResolver = std::make_shared<CompetenceResolver>(5);
	this->weightsService = std::make_shared<WeightsService>();
	this->weightsStorage = std::make_shared<WeightsStorage>();
}

LabLogic::LabLogic(std::shared_ptr<Matrix> input) {
	this->initialMatrix = input;
	this->analysResolver = std::make_shared<AnalysingCoeffsResolver>();
	this->competResolver = std::make_shared<CompetenceResolver>(5);
	this->weightsService = std::make_shared<WeightsService>();
	this->weightsStorage = std::make_shared<WeightsStorage>(*input);
}

LabLogic::~LabLogic() {
}

void LabLogic::setInitialMatrix(std::shared_ptr<Matrix> initialMatrix) {
	this->initialMatrix = initialMatrix;
	this->weightsStorage->setPoll(*initialMatrix);
}

void LabLogic::calculate() {
	/**ANALYSE INITIAL MATRIX*/
	this->concordanceCoeff = this->analysResolver->getConcordanceCoefficient(
		                                                  this->initialMatrix);
	this->spearmanCorrel = this->analysResolver->getSpearmanCorrelation(
		                                                  this->initialMatrix);
	/**CALCULATE WEIGHTS*/
	this->weightsStorage->setIndividualWeights(
		*this->weightsService->getIndividualWeights(*this->initialMatrix));
	this->weightsStorage->setNormalizedWeights(
		*this->weightsService->getNormalizedWeights(
			*this->weightsStorage->getIndividualWeights()));
	/**COMPETENCE CALCULATION*/
	this->competResolver->resolveCompetence(
		                         this->weightsStorage->getNormalizedWeights());
	/**ALPHA*/
	this->significance = this->analysResolver->getSignificance(
		                          this->getConcordanceCoefficient(), *initialMatrix);
}

double LabLogic::getConcordanceCoefficient() {
	return this->concordanceCoeff;
}

double LabLogic::getSignificance() {
	return this->significance;
}

std::shared_ptr<Matrix> LabLogic::getSpearmanCorrelation() {
	return this->spearmanCorrel;
}

std::shared_ptr<MathVector> LabLogic::getCompetence() {
	return this->competResolver->getCompetence();
}

std::shared_ptr<Matrix> LabLogic::getIndividualWeights() {
	return this->weightsStorage->getIndividualWeights();
}

std::shared_ptr<Matrix> LabLogic::getNormalizedWeights() {
	return this->weightsStorage->getNormalizedWeights();
}

std::shared_ptr<MathVector> LabLogic::getCentroid() {
	return this->weightsService->getCentroid(*this->getNormalizedWeights());
}
