#include "../../include/expert_method/competence/CompetenceResolver.hpp"

CompetenceResolver::CompetenceResolver() : numIterations(4) {
	this->vecService = std::shared_ptr<MathVectorService>();
	this->matrService = std::shared_ptr<MatrixService>();
}

CompetenceResolver::CompetenceResolver(unsigned iterations) :
	                                   numIterations(iterations) {
	this->vecService = std::shared_ptr<MathVectorService>();
	this->matrService = std::shared_ptr<MatrixService>();
}

CompetenceResolver::CompetenceResolver(std::shared_ptr<Matrix> competence) :
	                                                         numIterations(4) {
	this->vecService = std::shared_ptr<MathVectorService>();
	this->matrService = std::shared_ptr<MatrixService>();
	this->resolveCompetence(competence);
}

CompetenceResolver::CompetenceResolver(unsigned iterations,
	                                   std::shared_ptr<Matrix> competence) :
	                                              numIterations(iterations) {
	this->vecService = std::shared_ptr<MathVectorService>();
	this->matrService = std::shared_ptr<MatrixService>();
	this->resolveCompetence(competence);
}

CompetenceResolver::~CompetenceResolver() {
	this->competence.reset();
}

void CompetenceResolver::setNumIterations(unsigned iterations) {
	this->numIterations = iterations;
}

unsigned CompetenceResolver::getNumIterations() {
	return this->numIterations;
}

void CompetenceResolver::resolveCompetence(std::shared_ptr<Matrix> individualWeights) {
	this->calculateInitialApproximation(individualWeights->getColsSize());
	auto matrB = std::make_shared<Matrix>(
		this->matrService->getTransposed(*individualWeights) * *individualWeights);
	for (int i = 0; i < this->numIterations; ++i) {
		this->calculateNextApproximation(*matrB * *(this->competence));
	}
}

std::shared_ptr<MathVector> CompetenceResolver::getCompetence() {
	return this->competence;
}

void CompetenceResolver::calculateInitialApproximation(size_t size) {
	this->competence = std::make_shared<MathVector>(size);
	for (int i = 0; i < size; ++i) {
		this->competence->at(i) = 1.0 / size;
	}
}

void CompetenceResolver::calculateNextApproximation(MathVector& vecUnweightCoeffs) {
	double vecSumm = this->vecService->getVectorSumm(vecUnweightCoeffs);
	for (int i = 0; i < vecUnweightCoeffs.size(); ++i) {
		this->competence->at(i) = vecUnweightCoeffs.at(i) / vecSumm;
	}
}
