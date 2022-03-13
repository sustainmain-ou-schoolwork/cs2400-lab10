/**
 *   @file: lab10.cc
 * @author: Josh Marusek
 *   @date: 2021-10-29
 *  @brief: Reads from a cost file and a part name file, then prints the most and least expensive parts
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

/**
 *  Function: indexOfSmallest
 *  @brief Returns the index of the smallest number.
 * 
 *  @param numbers the array of numbers to check
 *  @param length the length of the array
 *  @return index of the smallest number
 */
int indexOfSmallest(const double numbers[], int length);

/**
 *  Function: indexOfGreatest
 *  @brief Returns the index of the greatest number.
 * 
 *  @param numbers the array of numbers to check
 *  @return index of the greatest number
 */
int indexOfGreatest(const double numbers[], int length);


int main(int argc, char const *argv[]) {
    string parts[6];
    double costs[6];
    string partIn;
    double costIn;

    ifstream partsFile;
    ifstream costsFile;
    partsFile.open("data2.txt");
    costsFile.open("data1.txt");

    if (costsFile.fail() || partsFile.fail()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    int i = 0;
    while (getline(partsFile, partIn)) {
        parts[i] = partIn;
        costsFile >> costIn;
        costs[i] = costIn;
        i++;
    }

    cout << "The name of the most expensive part is " << parts[indexOfGreatest(costs, 6)];
    cout << " ($" << fixed << setprecision(2) << costs[indexOfGreatest(costs, 6)] << ")" << endl;
    cout << "The name of the least expensive part is " << parts[indexOfSmallest(costs, 6)];
    cout << " ($" << fixed << setprecision(2) << costs[indexOfSmallest(costs, 6)] << ")" << endl;

    return EXIT_SUCCESS;
}/// main


int indexOfSmallest(const double numbers[], int length) {
    double smallest = numbers[0];
    int index = 0;

    for (int i = 1; i < length; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
            index = i;
        }
    }

    return index;
}

int indexOfGreatest(const double numbers[], int length) {
    double greatest = numbers[0];
    int index = 0;

    for (int i = 1; i < length; i++) {
        if (numbers[i] > greatest) {
            greatest = numbers[i];
            index = i;
        }
    }

    return index;
}