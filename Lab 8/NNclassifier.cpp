#include "NNclassifier.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

NNClassifier::NNClassifier() {
	
}

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

		Vector3 newData = Vector3(stof(x), stof(y), stof(z));

		trainingData.push_back(newData);
		trainingDataTable.insert({ newData, stoi(label) });
	}

	return true;
}

bool NNClassifier::test(string filePath, int& outErrors) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		outErrors = -1;
		return outErrors;
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

		map<float, tuple<Vector3, int>> distances;
		for (Vector3 trainingVec : trainingData) {
			int label = trainingDataTable[trainingVec];
			float dist = newData.distance(trainingVec);
			distances.insert({ dist, { trainingVec, label } });
		}

		int testLabel = get<1>(distances[distances.begin()->first]);
		if (label != testLabel) {
			outErrors++;
		}
	}

	return outErrors;
}

bool NNClassifier::predict(string filePath) {
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) {
		return;
	}

	string line;
	while (getline(fin, line)) {

		istringstream lineStream = istringstream(line);

		string x, y, z;
		getline(lineStream, x, ',');
		getline(lineStream, y, ',');
		getline(lineStream, z, ',');

		Vector3 newData = Vector3(stof(x), stof(y), stof(z));

		map<float, tuple<Vector3, int>> distances;
		for (Vector3 trainingVec : trainingData) {
			int label = trainingDataTable[trainingVec];
			float dist = newData.distance(trainingVec);
			distances.insert({ dist, { trainingVec, label } });
		}

		int closest = get<1>(distances[distances.begin()->first]);

		cout << newData << ", " << closest << endl;
	}
}

vector<Vector3>& NNClassifier::GetTrainingData() {
	return trainingData;
}
