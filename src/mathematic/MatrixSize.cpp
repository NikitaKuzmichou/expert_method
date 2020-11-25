#include "../../include/mathematic/exceptions/MatrixSize.hpp"

MatrixSizeException::MatrixSizeException() : exception() {

}

MatrixSizeException::MatrixSizeException(char const* const _Message) : exception(_Message) {

}

char const* MatrixSizeException::what() const {
	return "Mathematic matrixs has different lengths";
}
