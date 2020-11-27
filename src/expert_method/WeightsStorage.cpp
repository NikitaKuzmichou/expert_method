#include "../../include/expert_method/weights/WeightsStorage.hpp"

WeightsStorage::WeightsStorage() {

}

WeightsStorage::WeightsStorage(Matrix& poll) : poll(&poll) {

}

WeightsStorage::~WeightsStorage() {
	this->individualWeights.reset();
	this->normalizedWeights.reset();
	this->poll.reset();
}

void WeightsStorage::setPoll(Matrix& poll) {
	this->poll = std::make_shared<Matrix>(poll);
}

std::shared_ptr<Matrix> WeightsStorage::getPoll() {
	return this->poll;
}

void WeightsStorage::setIndividualWeights(Matrix& individWeig) {
	this->individualWeights = std::make_shared<Matrix>(individWeig);
}

std::shared_ptr<Matrix> WeightsStorage::getIndividualWeights() {
	return this->individualWeights;
}

void WeightsStorage::setNormalizedWeights(Matrix& normalWeig) {
	this->normalizedWeights = std::make_shared<Matrix>(normalWeig);
}

std::shared_ptr<Matrix> WeightsStorage::getNormalizedWeights() {
	return this->normalizedWeights;
}
