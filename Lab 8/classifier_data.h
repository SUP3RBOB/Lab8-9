#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "vector3.h"
#define MAX_ORIENTATIONS 6

/// @brief		this is a brief description for the Gps class
/// 
/// add more detail description here about the Gps class
/// @author ___
/// @date 24/04/10

class ClassifierData {
private:
	Vector3 vector;
	int label;
	std::string orientation;

	static std::unordered_map<int, std::string> orientations;
	void updateOrientation();

public:

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	ClassifierData();

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	ClassifierData(Vector3 vector, int label);


	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return if the return value is true that means the Gps is started
	Vector3 getVector();

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return if the return value is true that means the Gps is started
	int getLabel();

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return if the return value is true that means the Gps is started	
	std::string getOrientation();


	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return
	void setVector(Vector3 vector);

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return
	void setLabel(int label);


	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return
	friend std::ostream& operator <<(std::ostream& cout, ClassifierData data);

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	/// @ return
	friend std::ofstream& operator <<(std::ofstream& fout, ClassifierData data);
};