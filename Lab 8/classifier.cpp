#include "classifier.h"

using namespace std;

// Returns the list of predicted data
vector<ClassifierData>& Classifier::getPredictedData() {
	return predictedData;
}