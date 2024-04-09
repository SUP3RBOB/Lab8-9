// Lab 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "NNclassifier.h"
#include <string>
#include "file_io_exception.h"

using namespace std;

void ClearCin();

int main() {
    int maxOptions = 3;
    int option = 0;

    while (option < 1 || option > maxOptions) {
        cout << "Choose a classifier to use: " << endl;
        cout << "[1] - NN Classifier" << endl;
        cout << "[2] - KNN Classifier" << endl;
        cout << "[3] - Another Classifier" << endl;
        cin >> option;

        ClearCin();
    }

    if (option == 2 || option == 3) {
        cout << "This classifier have not been implemented yet" << endl;
        exit(EXIT_SUCCESS);
    }

    maxOptions = 2;
    option = 0;

    while (option < 1 || option > maxOptions) {
        cout << endl;

        cout << "Would you like to enter custom data or import from a file?" << endl;
        cout << "[1] - Custom data" << endl;
        cout << "[2] - Import from file" << endl;
        cin >> option;

        ClearCin();
    }

    NNClassifier classifier = NNClassifier();
    try {
        classifier.train("trainingData.txt");
    } catch (FileIOException e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    int errors;
    try {
        classifier.test("testingData.txt", errors);
    } catch (FileIOException e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (errors > 0) {
        cout << "There is an error with the testing data or algorithm" << endl;
        exit(EXIT_FAILURE);
    }

    if (option == 1) {
        cout << endl;
        cout << "Enter a valid vector (x,y,z) for the classifier to predict:" << endl;

        string vecString;
        cin >> vecString;

        Vector3 vec = Vector3::parse(vecString);
        classifier.predictSingle(vec);
        
        for (ClassifierData data : classifier.getPredictedData()) {
            cout << data << endl;
        }

        exit(EXIT_SUCCESS);
    }

    if (option == 2) {
        cout << endl;
        cout << "Enter a file path containing data for the classifier to predict:" << endl;

        string filePath;
        getline(cin, filePath);

        try {
            classifier.predict(filePath);
        } catch (FileIOException e) {
            cout << e.what() << endl;
            exit(EXIT_FAILURE);
        }

        cout << "Predicted data successfully outputed to results.txt" << endl;
        exit(EXIT_SUCCESS);
    }

    return 0;
}

void ClearCin() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
