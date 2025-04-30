#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function prototypes
double getJudgeScore(int judgeNumber);
double findLowest(double a, double b, double c, double d, double e);
double findHighest(double a, double b, double c, double d, double e);
double calcAverage(double a, double b, double c, double d, double e);

int main() {
    cout << "Talent Competition Score Calculator\n\n";

    double score1 = getJudgeScore(1);
    double score2 = getJudgeScore(2);
    double score3 = getJudgeScore(3);
    double score4 = getJudgeScore(4);
    double score5 = getJudgeScore(5);

    double finalScore = calcAverage(score1, score2, score3, score4, score5);

    cout << fixed << setprecision(2);
    cout << "\nFinal score (after dropping highest and lowest): " << finalScore << endl;

    return 0;
}

// Get a valid score between 0 and 10
double getJudgeScore(int judgeNumber) {
    double score;

    while (true) {
        cout << "Enter score for judge #" << judgeNumber << " (0 - 10): ";
        cin >> score;

        if (cin.fail() || score < 0.0 || score > 10.0) {
            cout << "Invalid input. Score must be between 0 and 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return score;
        }
    }
}

// Find the lowest of five scores
double findLowest(double a, double b, double c, double d, double e) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    return min;
}

// Find the highest of five scores
double findHighest(double a, double b, double c, double d, double e) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (e > max) max = e;
    return max;
}

// Calculate average after dropping highest and lowest
double calcAverage(double a, double b, double c, double d, double e) {
    double total = a + b + c + d + e;
    double highest = findHighest(a, b, c, d, e);
    double lowest = findLowest(a, b, c, d, e);
    return (total - highest - lowest) / 3.0;
}