/*
* PROG71020 - Lab 8 - 9 Machine Learning
* Harris Ibrahimi - Chris Hunt - Joshua Salmons
*/

#include "NNclassifier.h"
#include <string>
#include "file_io_exception.h"

using namespace std;

// Function that clears the input buffer
void ClearCin();

int main() {
    // Menu variables
    int maxOptions = 3;
    int option = 0;

    // Keep asking the user for a valid input
    while (option < 1 || option > maxOptions) {
        cout << "Choose a classifier to use: " << endl;
        cout << "[1] - NN Classifier" << endl;
        cout << "[2] - KNN Classifier" << endl;
        cout << "[3] - Another Classifier" << endl;
        cin >> option;

        ClearCin();
    }

    // Exit program if the non implemented classifiers are selected
    if (option == 2 || option == 3) {
        cout << "This classifier have not been implemented yet" << endl;
        exit(EXIT_SUCCESS);
    }

    // Update menu variables for next menu
    maxOptions = 2;
    option = 0;

    // Keep asking the user for how they want to import data for the machine learning classifiers
    while (option < 1 || option > maxOptions) {
        cout << endl;

        cout << "Would you like to enter custom data or import from a file?" << endl;
        cout << "[1] - Custom data" << endl;
        cout << "[2] - Import from file" << endl;
        cin >> option;

        ClearCin();
    }

    // Create an instance of the nearest neighbour classifier
    NNClassifier classifier = NNClassifier();

    // Train the classifier with the training data
    try {
        classifier.train("trainingData.txt");
    } catch (FileIOException e) {
        // Exit program if exception is caught
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // Test the classifier's algorithm with the testing data
    int errors;
    try {
        classifier.test("testingData.txt", errors);
    } catch (FileIOException e) {
        // Exit program if exception is caught
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // Exit program if more than zero errors occured
    if (errors > 0) {
        cout << "There are " << errors << " errors with the testing data" << endl;
        exit(EXIT_FAILURE);
    }

    // Option 1: Ask user for a singular vector and predict its data using the classifier's algorithm
    if (option == 1) {
        cout << endl;
        cout << "Enter a valid vector (x,y,z) for the classifier to predict:" << endl;

        // Obtain input from user
        string vecString;
        cin >> vecString;

        // Parse string into vector
        Vector3 vec = Vector3::parse(vecString);

        // Predict vector label and orientation
        classifier.predictSingle(vec);
        
        // Print out results
        cout << classifier.getPredictedData().back() << endl;

        exit(EXIT_SUCCESS);
    }

    // Option 2: Predict a collection of data from a file
    if (option == 2) {
        cout << endl;
        cout << "Enter a file path containing data for the classifier to predict:" << endl;

        string filePath;
        getline(cin, filePath);

        // Predict data from the file
        try {
            classifier.predict(filePath);
        } catch (FileIOException e) {
            // Exit program if exception is caught
            cout << e.what() << endl;
            exit(EXIT_FAILURE);
        }

        cout << "Predicted data successfully outputed to results.txt" << endl;
        exit(EXIT_SUCCESS);
    }

    return 0;
}

// Function that clears the input buffer
void ClearCin() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
