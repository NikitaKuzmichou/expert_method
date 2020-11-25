#ifndef WEIGHTS_SERVICE
#define WEIGHTS_SERVICE

#include "../../mathematic/structures/Matrix.hpp"

class WeightsService {
public:
	std::shared_ptr<Matrix> getIndividualWeights(Matrix& matrix);
	std::shared_ptr<Matrix> getNormalizedWeights(Matrix& matrix);
};

#endif // !WEIGHTS_SERVICE
