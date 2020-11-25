#ifndef MATHEMATIC_VECTOR_SERVICE
#define MATHEMATIC_VECTOR_SERVICE

#include "../structures/MathVector.hpp"

class MathVectorService {
public:
	double getVectorSumm(MathVector& vec);
	double getMin(MathVector& vec);
	double getMax(MathVector& vec);
};

#endif // !MATHEMATIC_VECTOR_SERVICE
