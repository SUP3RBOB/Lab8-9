#include "vector3.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Default constructor that creates a zero vector (0, 0, 0)
Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

// Parameterized constructor that creates a new 3D vector with the specified parameters
Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// Getter method that returns the X value of the vector
float Vector3::getX() {
	return x;
}

// Setter method that set the X value of the vector
void Vector3::setX(float x) {
	this->x = x;
}

// Getter method that returns the Y value of the vector
float Vector3::getY() {
	return y;
}

// Setter method that set the Y value of the vector
void Vector3::setY(float x) {
	this->y = y;
}

// Getter method that returns the Z value of the vector
float Vector3::getZ() {
	return z;
}

// Setter method that set the Z value of the vector
void Vector3::setZ(float x) {
	this->z = z;
}

// Calculates the distance between a vector and another vector
float Vector3::distance(Vector3& v) {
	return sqrt(pow(x - v.x, 2.f) + pow(y - v.y, 2.f) + pow(z - v.z, 2.f));
}

// Parses string data into a new vector
Vector3 Vector3::parse(std::string vecString) {
	istringstream stream = istringstream(vecString);
	string x, y, z;
	getline(stream, x, ',');
	getline(stream, y, ',');
	getline(stream, z, ',');
	return Vector3(stof(x), stof(y), stof(z));
}

// Operator overload that allows for cout to print a vector
ostream& operator <<(ostream& cout, Vector3& v) {
	cout << v.x << "," << v.y << "," << v.z;
	return cout;
}

// Operator overload that allows for a vector to be printed to a file stream
std::ofstream& operator <<(std::ofstream& fout, Vector3& v) {
	fout << v.x << "," << v.y << "," << v.z;
	return fout;
}
