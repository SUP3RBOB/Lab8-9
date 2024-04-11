#include "classifier_data.h"

using namespace std;

// Default constructor that creates empty classifier data
ClassifierData::ClassifierData() {
    vector = Vector3();
    label = 0;
    orientation = "";
}

// Paramaterized constructor that creates classifier data with the specified values
ClassifierData::ClassifierData(Vector3 vector, int label) {
    this->vector = vector;
    this->label = label;

    updateOrientation();
}

// Gets the vector of the classifier data
Vector3 ClassifierData::getVector() {
    return vector;
}

// Gets the label of the classifier data
int ClassifierData::getLabel() {
    return label;
}

// Gets the orientation label of the classifier data
string ClassifierData::getOrientation() {
    return orientation;
}

// Sets the vector of the classifier data
void ClassifierData::setVector(Vector3 vector) {
    this->vector = vector;
}

// Sets the label of the classifier data
void ClassifierData::setLabel(int label) {
    this->label = label;
    updateOrientation();
}

// Basic map of labels to orientations
unordered_map<int, string> ClassifierData::orientations = {
    { 1, "Face up" },
    { 2, "Face down" },
    { 3, "Portrait" },
    { 4, "Portrait upside down" },
    { 5, "Landscape left" },
    { 6, "Landscape right" },
};

// Internal method used to update the orientation based on the label's value
void ClassifierData::updateOrientation() {
    if (label < 1 || label > MAX_ORIENTATIONS) {
        orientation = "";
        return;
    }

    orientation = orientations[label];
}

// Operator overload that allows for cout to print classifier data
std::ostream& operator <<(std::ostream& cout, ClassifierData data) {
    cout << data.vector << "," << data.label << "," << data.orientation;
    return cout;
}

// Operator overload that allows for classifier data to be printed to a file stream
std::ofstream& operator <<(std::ofstream& fout, ClassifierData data) {
    fout << data.vector << "," << data.label << "," << data.orientation;
    return fout;
}
