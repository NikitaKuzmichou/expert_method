#include "../../include/mathematic/structures/MathVector.hpp"
#include "../../include/mathematic/exceptions/MathVectorSize.hpp"

MathVector::MathVector() {
	this->vector = std::make_shared<std::vector<double>>();
}

MathVector::MathVector(size_t size) {
	this->vector = std::make_shared<std::vector<double>>(size);
}

MathVector::~MathVector() {
	this->vector.reset();
}

double& MathVector::at(int i) {
	return this->vector->at(i);
}

size_t MathVector::size() const {
	return this->vector->size();
}

MathVector& MathVector::operator= (MathVector& right) {
	if (this == &right) {
		return *this;
	}
	this->vector->resize(right.size());
	for (int i = 0; i < right.size(); ++i) {
		this->vector->at(i) = right.at(i);
	}
	return *this;
}

double& MathVector::operator[] (int index) {
	return this->at(index);
}

MathVector operator+ (MathVector& vec1, MathVector& vec2) {
	if (vec1.size() != vec2.size()) {
		throw MathVectorSizeException();
	}
	MathVector result = MathVector(vec1.size());
	for (int i = 0; i < vec1.size(); ++i) {
		result.at(i) = vec1.vector->at(i) + vec2.vector->at(i);
	}
	return result;
}

MathVector operator- (MathVector& vec1, MathVector& vec2) {
	if (vec1.size() != vec2.size()) {
		throw MathVectorSizeException();
	}
	MathVector result = MathVector(vec1.size());
	for (int i = 0; i < vec1.size(); ++i) {
		result.at(i) = vec1.vector->at(i) - vec2.vector->at(i);
	}
	return result;
}

MathVector operator* (MathVector& vec, double scalar) {
	MathVector result = MathVector(vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		result.at(i) = vec.vector->at(i) * scalar;
	}
	return result;
}

MathVector operator* (double scalar, MathVector& vec) {
	return vec * scalar;
}

MathVector operator/ (MathVector& vec, double scalar) {
	return vec * (1.0 / scalar);
}

