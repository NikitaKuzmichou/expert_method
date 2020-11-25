#ifndef MATRIX_SIZE_EXCEPTION
#define MATRIX_SIZE_EXCEPTION

#include <exception>

class MatrixSizeException : public std::exception {
public:
	MatrixSizeException();
	MatrixSizeException(char const* const _Message);
	char const* what() const override;
};

#endif // !MATH_VECTOR_SIZE_EXCEPTION
