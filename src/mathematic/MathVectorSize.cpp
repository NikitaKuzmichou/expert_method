#include "../../include/mathematic/exceptions/MathVectorSize.hpp"

char const* MathVectorSizeException::what() const {
	return "Mathematic vectors has different lengths";
}
