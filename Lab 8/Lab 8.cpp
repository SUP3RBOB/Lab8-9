// Lab 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NNclassifier.h"

using namespace std;

int main() {
    NNClassifier classifier = NNClassifier();
    classifier.train("trainingData.txt");
    
    int errors = classifier.test("testingData.txt");
    cout << "There have been " << errors << " found in the test data" << endl;
    
    classifier.predict("unknownData.txt");
}