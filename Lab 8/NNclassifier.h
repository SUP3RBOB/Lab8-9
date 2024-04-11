#pragma once
#include "classifier.h"

/// @brief Classifier class that implements nearest neighbour machine learning
/// A classifier class that implement nearest neighbour machine learning
/// @author Harris Ibrahimi, Chris Hunt, Joshua Salmons
/// @date 24/04/10
class NNClassifier : public Classifier {
public:

	/// @brief Obtains data from a file to learn from
	/// Method that obtains classifier data from a file and uses it for learning and prediction
	/// @param filePath: The path to the file with the data you want to import
	virtual void train(std::string filePath) override;

	/// @brief Obtains test data from a file to check if the algorithm is working
	/// Method that obtains test classifier data from a file and uses it for testing the prediction algortihm
	/// @param filePath: The path to the file with the data you want to import
	/// @param outErrors: Output parameter that returns the amount of errors found when testing data with the algorithm
	virtual void test(std::string filePath, int& outErrors) override;

	/// @brief Obtains data from a file to predict
	/// Method that obtains classifier data from a file and predicts its label and orientation
	/// @param filePath: The path to the file with the data you want to import
	virtual void predict(std::string filePath) override;

	/// @brief Predicts the label and orientation of a vector
	/// Method that predicts the label and orientation of a single three dimensional vector 
	/// @param vec: A referemce to the vector you want the label and orientation of
	void predictSingle(Vector3& vec);
};

