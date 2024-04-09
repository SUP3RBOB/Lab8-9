#pragma once
#include <iostream>

class Vector3 {
private:
	float x;
	float y;
	float z;

public:
	Vector3();
	Vector3(float x, float y, float z);

	float getX();
	void setX(float x);

	float getY();
	void setY(float x);

	float getZ();
	void setZ(float x);

	float distance(Vector3& v);

	friend std::ostream& operator <<(std::ostream& cout, Vector3& v);

	struct VectorHash {
		std::size_t operator ()(const Vector3& vec) const;
	};

	bool operator ==(const Vector3& vec) const;
};

