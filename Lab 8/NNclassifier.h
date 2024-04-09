#pragma once
#include "classifier.h"
#include <iostream>
#include "classifier_data.h"

class NNClassifier : public Classifier {
private:
	std::vector<ClassifierData> trainingData;
	std::vector<ClassifierData> predictedData;

public:
	virtual bool train(std::string filePath) override;
	virtual bool test(std::string filePath, int& outErrors) override;
	virtual bool predict(std::string filePath) override;

	std::vector<ClassifierData>& getPredictedData();
};

