 #include <iostream>
#include <limits>
#include <cctype>
using namespace std;
// Function declarations
double getPositiveInput(const string& prompt);
double calculatePerimeter(double length, double width);
double calculateArea(double length, double width);
bool askToContinue();
int main() {
    bool continueProcessing = true;

    while (continueProcessing) {
        double length = getPositiveInput("Enter the length of the rectangle: ");
        double width = getPositiveInput("Enter the width of the rectangle: ");

        double perimeter = calculatePerimeter(length, width);
        double area = calculateArea(length, width);

        cout << "Perimeter: " << perimeter << endl;
        cout << "Area: " << area << endl;

        continueProcessing = askToContinue();
    }

    cout << "Thank you for using the Rectangle Calculator!" << endl;
    return 0;
}

// Function to get positive input with validation
double getPositiveInput(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a non-negative number." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            return value;
        }
    }
}

// Function to calculate perimeter
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate area
double calculateArea(double length, double width) {
    return length * width;
}

// Function to ask user if they want to continue
bool askToContinue() {
    char response;
    cout << "Do you want to calculate another rectangle? (Y/N): ";
    cin >> response;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean up input buffer
    return (tolower(response) == 'y');
}

