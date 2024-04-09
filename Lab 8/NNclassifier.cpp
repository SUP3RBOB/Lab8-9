#include "NNclassifier.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "file_io_exception.h"

using namespace std;

void NNClassifier::train(string filePath) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		throw FileIOException();
	}

	string line;
	while (getline(fin, line)) {
		istringstream lineStream = istringstream(line);

		string x, y, z, label;
		getline(lineStream, x, ',');
		getline(lineStream, y, ',');
		getline(lineStream, z, ',');
		getline(lineStream, label);

		ClassifierData newData = ClassifierData(Vector3(stof(x), stof(y), stof(z)), stoi(label));

		trainingData.push_back(newData);
	}

	fin.close();
}

void NNClassifier::test(string filePath, int& outErrors) {
	outErrors = 0;

	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		outErrors = -1;
		throw FileIOException();
	}

	string line;
	while (getline(fin, line)) {
		istringstream lineStream = istringstream(line);

		string x, y, z, sLabel;
		getline(lineStream, x, ',');
		getline(lineStream, y, ',');
		getline(lineStream, z, ',');
		getline(lineStream, sLabel);

		Vector3 newData = Vector3(stof(x), stof(y), stof(z));
		int label = stoi(sLabel);

		map<float, ClassifierData> distances;
		for (ClassifierData data : trainingData) {
			Vector3 otherVec = data.getVector();
			float dist = newData.distance(otherVec);
			distances.insert({ dist, data });
		}

		int testLabel = distances[distances.begin()->first].getLabel();
		if (label != testLabel) {
			outErrors++;
		}
	}

	fin.close();
}

void NNClassifier::predict(string filePath) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		throw FileIOException();
	}

	string line;
	while (getline(fin, line)) {
		istringstream lineStream = istringstream(line);

		string x, y, z;
		getline(lineStream, x, ',');
		getline(lineStream, y, ',');
		getline(lineStream, z, ',');

		Vector3 newData = Vector3(stof(x), stof(y), stof(z));

		map<float, ClassifierData> distances;
		for (ClassifierData data : trainingData) {
			Vector3 otherVec = data.getVector();
			float dist = newData.distance(otherVec);
			distances.insert({ dist, data });
		}

		int closest = distances[distances.begin()->first].getLabel();
		predictedData.push_back(ClassifierData(newData, closest));
	}

	fin.close();

	ofstream fout;
	fout.open("results.txt");
	if (!fout.is_open()) {
		throw FileIOException();
	}

	for (ClassifierData data : predictedData) {
		fout << data << endl;
	}

	fout.close();
}

void NNClassifier::predictSingle(Vector3& vec) {
	map<float, ClassifierData> distances;
	for (ClassifierData data : trainingData) {
		Vector3 otherVec = data.getVector();
		float dist = vec.distance(otherVec);
		distances.insert({ dist, data });
	}

	int closest = distances[distances.begin()->first].getLabel();
	predictedData.push_back(ClassifierData(vec, closest));
}
