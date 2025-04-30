#include <iostream>
#include <iomanip>
#include <cmath> // For ceil
#include <limits>
using namespace std;

// Constants
const double SQUARE_FEET_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_COST_PER_HOUR = 25.0;

// Function Prototypes
int getNumberOfRooms();
double getPricePerGallon();
double getWallSpace(int roomNumber);
double calculateTotalWallSpace(int numRooms);
int calculateGallonsRequired(double totalWallSpace);
double calculateLaborHours(int gallons);
double calculatePaintCost(int gallons, double pricePerGallon);
double calculateLaborCharges(double hours);
void displayResults(int gallons, double hours, double paintCost, double laborCost, double totalCost);

int main() {
    int numberOfRooms = getNumberOfRooms();
    double pricePerGallon = getPricePerGallon();

    double totalWallSpace = calculateTotalWallSpace(numberOfRooms);
    int gallonsRequired = calculateGallonsRequired(totalWallSpace);
    double laborHours = calculateLaborHours(gallonsRequired);
    double paintCost = calculatePaintCost(gallonsRequired, pricePerGallon);
    double laborCost = calculateLaborCharges(laborHours);
    double totalCost = paintCost + laborCost;

    displayResults(gallonsRequired, laborHours, paintCost, laborCost, totalCost);
    return 0;
}

// Input validation functions
int getNumberOfRooms() {
    int rooms;
    while (true) {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
        if (cin.fail() || rooms < 1) {
            cout << "Invalid input. Number of rooms must be at least 1.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return rooms;
        }
    }
}

double getPricePerGallon() {
    double price;
    while (true) {
        cout << "Enter the price of the paint per gallon ($): ";
        cin >> price;
        if (cin.fail() || price < 10.0) {
            cout << "Invalid input. Price must be at least $10.00.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return price;
        }
    }
}

double getWallSpace(int roomNumber) {
    double space;
    while (true) {
        cout << "Enter the square feet of wall space for room #" << roomNumber << ": ";
        cin >> space;
        if (cin.fail() || space < 0.0) {
            cout << "Invalid input. Square footage must not be negative.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return space;
        }
    }
}

// Calculation functions
double calculateTotalWallSpace(int numRooms) {
    double total = 0.0;
    for (int i = 1; i <= numRooms; ++i) {
        total += getWallSpace(i);
    }
    return total;
}

int calculateGallonsRequired(double totalWallSpace) {
    return static_cast<int>(ceil(totalWallSpace / SQUARE_FEET_PER_GALLON));
}

double calculateLaborHours(int gallons) {
    return gallons * HOURS_PER_GALLON;
}

double calculatePaintCost(int gallons, double pricePerGallon) {
    return gallons * pricePerGallon;
}

double calculateLaborCharges(double hours) {
    return hours * LABOR_COST_PER_HOUR;
}

// Display output
void displayResults(int gallons, double hours, double paintCost, double laborCost, double totalCost) {
    cout << fixed << setprecision(2);
    cout << "\n===== Paint Job Estimate =====\n";
    cout << "Gallons of paint required : " << gallons << endl;
    cout << "Hours of labor required   : " << hours << endl;
    cout << "Cost of the paint         : $" << paintCost << endl;
    cout << "Labor charges             : $" << laborCost << endl;
    cout << "Total cost of paint job   : $" << totalCost << endl;
}