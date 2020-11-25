#ifndef WEIGHTS_STORAGE
#define WEIGHTS_STORAGE

#include "../../mathematic/structures/Matrix.hpp"

class WeightsStorage {
private:
	std::shared_ptr<Matrix> poll;
	std::shared_ptr<Matrix> individualWeights;
	std::shared_ptr<Matrix> normalizedWeights;
public:
	WeightsStorage();
	WeightsStorage(Matrix& poll);
	~WeightsStorage();
	void setPoll(Matrix& poll);
	std::shared_ptr<Matrix> getPoll();
	void setIndividualWeights(Matrix& individualWeights);
	std::shared_ptr<Matrix> getIndividualWeights();
	void setNormalizedWeights(Matrix& normalizedWeights);
	std::shared_ptr<Matrix> getNormalizedWeights();
};

#endif // !WEIGHTS_STORAGE
