#pragma once
#include <iostream>
#include <fstream>

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

	static Vector3 parse(std::string vecString);

	friend std::ostream& operator <<(std::ostream& cout, Vector3& v);
	friend std::ofstream& operator <<(std::ofstream& fout, Vector3& v);
};

