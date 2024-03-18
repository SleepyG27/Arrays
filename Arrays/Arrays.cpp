/*Jason, Samantha, Ravi, Sheila, and Ankit are preparing for an upcoming marathon. Each day of the week,
they run a certain number of miles and write them into a notebook. At the end of the week, they would
like to know the number of miles run each day, the total miles for the week, and average miles run each
day. Write a program to help them analyze their data. */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

string runners[NUM_RUNNERS];
int miles[NUM_RUNNERS][NUM_DAYS];

void readDataFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < NUM_RUNNERS; ++i) {
            file >> runners[i];
            for (int j = 0; j < NUM_DAYS; ++j) {
                file >> miles[i][j];
            }
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void calculateTotalAndAverage() {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles += miles[i][j];
        }
        double averageMiles = static_cast<double>(totalMiles) / NUM_DAYS;
        cout << setw(10) << left << runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(7) << miles[i][j];
        }
        cout << setw(8) << totalMiles << setw(10) << fixed << setprecision(2) << averageMiles << endl;
    }
}

int main() {
    // Read data from the file
    readDataFromFile("runners.txt");

    // Output the table
    cout << setw(10) << left << "Runner";
    for (int i = 1; i <= NUM_DAYS; ++i) {
        cout << setw(7) << "Day " + to_string(i);
    }
    cout << setw(8) << "Total" << setw(10) << "Average" << endl;

    // Calculate and output total and average miles for each runner
    calculateTotalAndAverage();

    return 0;
}