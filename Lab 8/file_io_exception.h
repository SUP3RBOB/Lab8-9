#pragma once
#include <iostream>
#include <exception>

/// @brief Exception class used by the classifiers for when failing to open a file
/// @date 24/04/10
class FileIOException : public std::exception {
public:

	/// @brief Returns the error message(s) that the exception throws
	/// @return The error message
	const char* what() const override;
};

