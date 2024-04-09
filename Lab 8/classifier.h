#pragma once
#include <iostream>

class Classifier {
protected:

public:
	virtual bool train(std::string filePath) = 0;
	virtual bool test(std::string filePath, int& ourErrors) = 0;
	virtual bool predict(std::string filePath) = 0;
};

