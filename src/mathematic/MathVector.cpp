#include "../../include/mathematic/structures/MathVector.hpp"
#include "../../include/mathematic/exceptions/MathVectorSize.hpp"

MathVector::MathVector() : vector() {

}

MathVector::MathVector(size_t size) : vector(size) {

}

MathVector::~MathVector() {

}

double& MathVector::at(int i) {
	return std::vector<double>::at(i);
}

size_t MathVector::size() const {
	return std::vector<double>::size();
}

MathVector& MathVector::operator= (MathVector& right) {
	if (this == &right) {
		return *this;
	}
	this->resize(right.size());
	for (int i = 0; i < right.size(); ++i) {
		this->at(i) = right.at(i);
	}
	return *this;
}

MathVector operator+ (MathVector& vec1, MathVector& vec2) {
	if (vec1.size() != vec2.size()) {
		throw MathVectorSizeException();
	}
	MathVector result = MathVector(vec1.size());
	for (int i = 0; i < vec1.size(); ++i) {
		result.at(i) = vec1.at(i) + vec2.at(i);
	}
	return result;
}

MathVector operator- (MathVector& vec1, MathVector& vec2) {
	if (vec1.size() != vec2.size()) {
		throw MathVectorSizeException();
	}
	MathVector result = MathVector(vec1.size());
	for (int i = 0; i < vec1.size(); ++i) {
		result.at(i) = vec1.at(i) - vec2.at(i);
	}
	return result;
}

MathVector operator* (MathVector& vec, double scalar) {
	MathVector result = MathVector(vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		result.at(i) = vec.at(i) * scalar;
	}
	return result;
}

MathVector operator* (double scalar, MathVector& vec) {
	return vec * scalar;
}

MathVector operator/ (MathVector& vec, double scalar) {
	return vec * (1.0 / scalar);
}

