#ifndef MATRIX_SERVICE
#define MATRIX_SERVICE

#include "../structures/Matrix.hpp"
#include "MathVectorService.hpp"

class MatrixService {
private:
	std::shared_ptr<MathVectorService> vecService;
public:
	MatrixService();
	double getMax(Matrix& matrix);
	double getMin(Matrix& matrix);
	Matrix getTransposed(Matrix& matrix);
};

#endif // !MATRIX_SERVICE
