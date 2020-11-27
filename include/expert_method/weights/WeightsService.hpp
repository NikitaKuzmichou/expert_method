#ifndef WEIGHTS_SERVICE
#define WEIGHTS_SERVICE

#include "../../mathematic/structures/Matrix.hpp"
#include "../../mathematic/structures/MathVector.hpp"
#include "../../mathematic/service/MathVectorService.hpp"

class WeightsService {
private:
	std::shared_ptr<MathVectorService> vecService;
public:
	WeightsService();
	std::shared_ptr<Matrix> getIndividualWeights(Matrix& matrix);
	std::shared_ptr<Matrix> getNormalizedWeights(Matrix& matrix);
	std::shared_ptr<MathVector> getCentroid(Matrix& matrix);
};

#endif // !WEIGHTS_SERVICE
