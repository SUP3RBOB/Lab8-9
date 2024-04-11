#pragma once
#include "classifier.h"

/// @brief Classifier class that implements Another Classifier
/// @author Harris Ibrahimi, Chris Hunt, Joshua Salmons
/// @date 24/04/10
class AnotherClassifier : public Classifier {
public:

	/// @brief Unfinished method that prints out its own name
	/// @param filePath: Path to the file
	virtual void train(std::string filePath) override;

	/// @brief Unfinished method that prints out its own name
	/// @param filePath: Path to the file
	/// @param outErrors: Output parameter that does absolutely nothing
	virtual void test(std::string filePath, int& outErrors) override;

	/// @brief Unfinished method that prints out its own name
	/// @param filePath: Path to the file
	virtual void predict(std::string filePath) override;
};

