#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function prototypes
int getAccidents(const string& region);
string findLowest(int north, int south, int east, int west, int central);

int main() {
    cout << "Enter the number of automobile accidents reported last year for each region.\n";

    int north = getAccidents("North");
    int south = getAccidents("South");
    int east = getAccidents("East");
    int west = getAccidents("West");
    int central = getAccidents("Central");

    string lowestRegion = findLowest(north, south, east, west, central);

    cout << "\nThe region with the fewest accidents is: " << lowestRegion << endl;

    return 0;
}

// Function to get accident input with validation
int getAccidents(const string& region) {
    int accidents;

    while (true) {
        cout << "Enter accidents for " << region << " region: ";
        cin >> accidents;

        if (cin.fail() || accidents < 0) {
            cout << "Invalid input. Please enter a number 0 or greater." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return accidents;
        }
    }
}

// Function to find the region with the lowest number of accidents
string findLowest(int north, int south, int east, int west, int central) {
    int min = north;
    string region = "North";

    if (south < min) {
        min = south;
        region = "South";
    }
    if (east < min) {
        min = east;
        region = "East";
    }
    if (west < min) {
        min = west;
        region = "West";
    }
    if (central < min) {
        min = central;
        region = "Central";
    }

    return region;
}
