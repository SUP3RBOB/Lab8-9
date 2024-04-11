#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "vector3.h"
#define MAX_ORIENTATIONS 6

/// @brief Data type used by the cllassifiers for storing information
/// Basic data type that contains information that the classifier pulls from training and test data and also creates
/// for predicted data
/// @author Harris Ibrahimi, Chris Hunt, Joshua Salmons
/// @date 24/04/10
class ClassifierData {
private:

	/// @brief 3D vector of the data
	Vector3 vector;

	/// @brief Label of the 3D vector
	int label;

	/// @brief Orientation label of the 3D vector
	std::string orientation;

	/// @brief Basic map of labels to orientations
	static std::unordered_map<int, std::string> orientations;

	/// @brief Internal method used to update the orientation based on the label's value
	void updateOrientation();

public:

	/// @brief Default constructor that creates empty classifier data
	ClassifierData();

	/// @brief Paramaterized constructor that creates classifier data with the specified values
	/// @param Vector: The vector of the classifier data
	/// @param Label: The numbered label of the classifier data
	ClassifierData(Vector3 vector, int label);


	/// @brief Gets the vector of the classifier data
	/// @return The vector of the classifier data
	Vector3 getVector();

	/// @brief Gets the label of the classifier data
	/// @return The label of the classifier data
	int getLabel();

	/// @brief Gets the orientation label of the classifier data
	/// @return The orientation label of the classifier data
	std::string getOrientation();


	/// @brief Sets the vector of the classifier data
	/// @param vector: The new vector of the classifier data
	void setVector(Vector3 vector);

	/// @brief Sets the label of the classifier data
	/// @param label: The new label of the classifier data
	void setLabel(int label);


	/// @breif Operator overload that allows for cout to print classifier data
	/// @param cout: The main standard cout object used for outputting to the console
	/// @param data: The classifier data that needs to be printed to the console
	/// @return A reference to cout
	friend std::ostream& operator <<(std::ostream& cout, ClassifierData data);

	/// @breif Operator overload that allows for classifier data to be printed to a file stream
	/// @param fout: The main standard object used for printing text to a file
	/// @param data: The classifier data that needs to be printed to the file
	/// @return A reference to file stream object
	friend std::ofstream& operator <<(std::ofstream& fout, ClassifierData data);
};