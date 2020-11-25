#ifndef MATH_VECTOR_SIZE_EXCEPTION
#define MATH_VECTOR_SIZE_EXCEPTION

#include <exception>

class MathVectorSizeException : public std::exception {
public:
	char const* what() const override;
};

#endif // !MATH_VECTOR_SIZE_EXCEPTION
