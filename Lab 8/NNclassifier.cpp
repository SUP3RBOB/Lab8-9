#include "NNclassifier.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

bool NNClassifier::train(string filePath) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		return false;
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

	return true;
}

bool NNClassifier::test(string filePath, int& outErrors) {
	outErrors = 0;

	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		outErrors = -1;
		return false;
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

	return true;
}

bool NNClassifier::predict(string filePath) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		return false;
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

	return true;
}

vector<ClassifierData>& NNClassifier::getPredictedData() {
	return predictedData;
}
