#include "../../include/mathematic/service/MathVectorService.hpp"

double MathVectorService::getVectorSumm(MathVector& vec) {
	double summ = 0;
	for (int i = 0; i < vec.size(); ++i) {
		summ += vec.at(i);
	}
	return summ;
}

double MathVectorService::getMin(MathVector& vec) {
	double min = vec.at(0);
	for (int i = 1; i < vec.size(); ++i) {
		if (min > vec.at(i)) {
			min = vec.at(i);
		}
	}
	return min;
}

double MathVectorService::getMax(MathVector& vec) {
	double max = vec.at(0);
	for (int i = 1; i < vec.size(); ++i) {
		if (max < vec.at(i)) {
			max = vec.at(i);
		}
	}
	return max;
}