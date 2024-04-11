#pragma once
#include <iostream>
#include <vector>
#include "classifier_data.h"

/// @brief Class that all classifiers inherit from
/// Abstract class that serves as a base for all classifier classes
/// @author Harris Ibrahimi, Chris Hunt, Joshua Salmons
/// @date 24/04/10
class Classifier {
protected:

	/// @brief List of data obtained from training the classifier
	std::vector<ClassifierData> trainingData;

	/// @brief List of data that the classifier has predicted
	std::vector<ClassifierData> predictedData;

public:

	/// @brief Method to train the classifier
	/// Abstract method that serves as a base for a method to train the classifier
	/// @param filePath: Path to the file containg the data we want to train from
	virtual void train(std::string filePath) = 0;

	/// @brief Method to test the classifier's machine learning algorithm
	/// Abstract method that serves as a base for a method to test the classifier's algorithm for predicting data
	/// @param filePath: Path to the file containg the data we want to train from
	/// @param outErrors: The amount of errors found when testing the algorithm with the test data
	virtual void test(std::string filePath, int& outErrors) = 0;

	/// @brief Method to predict data
	/// Abstract method that serves as a base for a method to predict data using the classifier's algorithm
	/// @param filePath: Path to the file containg the data we want to train from
	/// @param outErrors: The amount of errors found when testing the algorithm with the test data
	virtual void predict(std::string filePath) = 0;

	/// @brief Returns the list of predicted data
	/// Returns a reference to the list of predicted data that the user can traverse or modify to their needs
	/// @return Reference to the list of data predicted by the instance of the classifier
	std::vector<ClassifierData>& getPredictedData();
};