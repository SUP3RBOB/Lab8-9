#pragma once
#include <iostream>
#include <exception>

/// @brief		this is a brief description for the Gps class
/// 
/// add more detail description here about the Gps class
/// @author ___
/// @date 23/04/15

class FileIOException : public std::exception {
public:

	/// @ brief
	/// @param accuracy this is the accuracy of the Gps and if it is set to true the Gps will have 
	/// best accuracy (10 cm) about the location
	/// and if it is set to false the accuracy will be lowest (> 1 m)
	const char* what() const override;
};

