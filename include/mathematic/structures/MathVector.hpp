#ifndef MATHEMATIC_VECTOR
#define MATHEMATIC_VECTOR

#include <vector>
#include <memory>

class MathVector {
private:
	std::shared_ptr<std::vector<double>> vector;
public:
	MathVector();
	MathVector(size_t size);
	~MathVector();
	double& at(int i);
	size_t size() const;
	MathVector& operator= (MathVector& vec);
	double& operator[] (int scalar);
	friend MathVector operator+ (MathVector& vec1, MathVector& vec2);
	friend MathVector operator- (MathVector& vec1, MathVector& vec2);
	friend MathVector operator* (MathVector& vec1, double scalar);
	friend MathVector operator* (double scalar, MathVector& vec);
	friend MathVector operator/ (MathVector& vec, double scalar);
};

#endif // !MATHEMATIC_VECTOR