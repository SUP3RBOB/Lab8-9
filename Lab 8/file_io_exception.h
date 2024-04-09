#pragma once
#include <iostream>
#include <exception>

class FileIOException : public std::exception {
public:
	const char* what() const override;
};

