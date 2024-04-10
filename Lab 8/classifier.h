#pragma once
#include <iostream>
#include <vector>
#include "classifier_data.h"



/// @brief		this is a brief description for the Gps class
/// 
/// add more detail description here about the Gps class
/// @author ___
/// @date 24/04/10

class Classifier {
protected:
	std::vector<ClassifierData> trainingData;
	std::vector<ClassifierData> predictedData;

public:

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	virtual void train(std::string filePath) = 0;

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	virtual void test(std::string filePath, int& ourErrors) = 0;

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	virtual void predict(std::string filePath) = 0;

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	std::vector<ClassifierData>& getPredictedData();
};