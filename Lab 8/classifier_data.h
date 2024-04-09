#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "vector3.h"
#define MAX_ORIENTATIONS 6

class ClassifierData {
private:
	Vector3 vector;
	int label;
	std::string orientation;

	static std::unordered_map<int, std::string> orientations;
	void updateOrientation();

public:
	ClassifierData();
	ClassifierData(Vector3 vector, int label);

	Vector3 getVector();
	int getLabel();
	std::string getOrientation();

	void setVector(Vector3 vector);
	void setLabel(int label);

	friend std::ostream& operator <<(std::ostream& cout, ClassifierData data);
	friend std::ofstream& operator <<(std::ofstream& fout, ClassifierData data);
};