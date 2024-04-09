#pragma once
#include "classifier.h"
#include <iostream>
#include <unordered_map>
#include "vector3.h"

class NNClassifier : public Classifier {
private:
	std::vector<Vector3> trainingData;
	std::unordered_map<Vector3, int, Vector3::VectorHash> trainingDataTable;

public:
	NNClassifier();

	virtual bool train(std::string filePath) override;
	virtual bool test(std::string filePath, int& outErrors) override;
	virtual bool predict(std::string filePath) override;

	std::vector<Vector3>& GetTrainingData();
};

