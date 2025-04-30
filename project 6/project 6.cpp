#include <iostream>
#include <iomanip>  // For std::setw and std::setprecision
using namespace std;

// Function prototype
double fahrenheitToCelsius(int fahrenheit);

int main() {
    cout << "Fahrenheit to Celsius Conversion Table\n";
    cout << "--------------------------------------\n";
    cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius\n";
    cout << "--------------------------------------\n";

    for (int f = 0; f <= 20; ++f) {
        double celsius = fahrenheitToCelsius(f);
        cout << setw(12) << f << setw(12) << fixed << setprecision(2) << celsius << endl;
    }

    return 0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}