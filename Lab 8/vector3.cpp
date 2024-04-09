#include "vector3.h"
#include <iostream>

using namespace std;

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::getX() {
	return x;
}

void Vector3::setX(float x) {
	this->x = x;
}

float Vector3::getY() {
	return y;
}

void Vector3::setY(float x) {
	this->y = y;
}

float Vector3::getZ() {
	return z;
}

void Vector3::setZ(float x) {
	this->z = z;
}

float Vector3::distance(Vector3& v) {
	return sqrt(pow(x - v.x, 2.f) + pow(y - v.y, 2.f) + pow(z - v.z, 2.f));
}

ostream& operator <<(ostream& cout, Vector3& v) {
	cout << v.x << ", " << v.y << ", " << v.z;
	return cout;
}

bool Vector3::operator ==(const Vector3& vec) const {
	return (this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z);
}

size_t Vector3::VectorHash::operator ()(const Vector3& vec) const {
	return std::hash<float>()(vec.x) ^ ((std::hash<float>()(vec.y) << 1) ^ (std::hash<float>()(vec.y) << 2));
}
