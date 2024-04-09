#pragma once
#include <iostream>
#include <vector>
#include "classifier_data.h"

class Classifier {
protected:
	std::vector<ClassifierData> trainingData;
	std::vector<ClassifierData> predictedData;

public:
	virtual void train(std::string filePath) = 0;
	virtual void test(std::string filePath, int& ourErrors) = 0;
	virtual void predict(std::string filePath) = 0;

	std::vector<ClassifierData>& getPredictedData();
};