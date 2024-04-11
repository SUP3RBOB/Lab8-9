#pragma once
#include <iostream>
#include <fstream>

/// @brief Basic implementation of a 3D vector
/// Basic implementation of a three deminesion vector with usfeul methods for calculating distance and parsing
/// data from a string.
/// @author Harris, Chris, Joshua
/// @date 24/04/10
class Vector3 {
private:

	/// @brief The X value of the vector
	float x;

	/// @brief The Y value of the vector
	float y;

	/// @brief The Z value of the vector
	float z;

public:
	/// @brief Default constructor that creates a zero vector (0, 0, 0)
	Vector3();

	/// @brief Parameterized constructor that creates a new 3D vector with the specified parameters
	/// @param x: The X value of the vector
	/// @param y: The Y value of the vector
	/// @param z: The Z value of the vector
	Vector3(float x, float y, float z);

	/// @brief Getter method that returns the X value of the vector
	/// @return The X value of the vector
	float getX();

	/// @brief Setter method that set the X value of the vector
	/// @param x: the new X value of the vector
	void setX(float x);

	/// @brief Getter method that returns the Y value of the vector
	/// @return The Y value of the vector
	float getY();

	/// @brief Setter method that set the Y value of the vector
	/// @param x: the new Y value of the vector
	void setY(float x);

	/// @brief Getter method that returns the Z value of the vector
	/// @return The Z value of the vector
	float getZ();

	/// @brief Setter method that set the Z value of the vector
	/// @param x: the new Z value of the vector
	void setZ(float x);

	/// @brief Calculates the distance between a vector and another vector
	/// Method that calulates and returns the distance between a vector and another vector using the
	/// euclidean distance formula
	/// @param v: Reference to another vector to calculate the distance from
	/// @return The distance between the two vectors
	float distance(Vector3& v);

	/// @brief Parses string data into a new vector
	/// Static method that takes in string data and attempts to parse/convert it into a vector
	/// Preffered string format: x,y,z
	/// @param vecString: The string to parse into a vector
	/// @return The newly parsed vector
	static Vector3 parse(std::string vecString);

	/// @breif Operator overload that allows for cout to print a vector
	/// @param cout: The main standard cout object used for outputting to the console
	/// @param v: The vector that needs to be printed to the console
	/// @return A reference to cout
	friend std::ostream& operator <<(std::ostream& cout, Vector3& v);

	/// @breif Operator overload that allows for a vector to be printed to a file stream
	/// @param fout: The main standard object used for printing text to a file
	/// @param v: The vector that needs to be printed to the file
	/// @return A reference to file stream object
	friend std::ofstream& operator <<(std::ofstream& fout, Vector3& v);
};

