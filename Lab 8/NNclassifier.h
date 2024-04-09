#pragma once
#include "classifier.h"
#include "classifier_data.h"

class NNClassifier : public Classifier {
public:
	virtual void train(std::string filePath) override;
	virtual void test(std::string filePath, int& outErrors) override;
	virtual void predict(std::string filePath) override;

	void predictSingle(Vector3& vec);
};

