#include "classifier_data.h"

using namespace std;

ClassifierData::ClassifierData() {
    vector = Vector3();
    label = 0;
    orientation = string();
}

ClassifierData::ClassifierData(Vector3 vector, int label) {
    this->vector = vector;
    this->label = label;

    updateOrientation();
}

Vector3 ClassifierData::getVector() {
    return vector;
}

int ClassifierData::getLabel() {
    return label;
}

string ClassifierData::getOrientation() {
    return orientation;
}

void ClassifierData::setVector(Vector3 vector) {
    this->vector = vector;
}

void ClassifierData::setLabel(int label) {
    this->label = label;
    updateOrientation();
}


unordered_map<int, string> ClassifierData::orientations = {
    { 1, "Face up" },
    { 2, "Face down" },
    { 3, "Portrait" },
    { 4, "Portrait upside down" },
    { 5, "Landscape left" },
    { 6, "Landscape right" },
};

void ClassifierData::updateOrientation() {
    if (label < 1 || label > MAX_ORIENTATIONS) {
        orientation = string();
        return;
    }

    orientation = orientations[label];
}

std::ostream& operator <<(std::ostream& cout, ClassifierData data) {
    cout << data.vector << "," << data.label << "," << data.orientation;
    return cout;
}
