#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Creating an ifstream object called inputFile and opening file1.txt for reading file1.txt
    std::ifstream inputFile("file1.txt");

    // Creating an ofstream object called outputFile and opening file2.txt for writing to file2.txt
    std::ofstream outputFile("file2.txt");

    // Checking if inputFile was opened successfully
    if (!inputFile.is_open()) {
        // Priting out error message if inputFile could not be opened
        std::cerr << "Error opening input file." << std::endl;
        // Returning 1 to main to signify unsuccessful run of the program
        return 1;
    }

    // Checking if outputFile was opened successfully
    if (!outputFile.is_open()) {
        // Printing out error message if outputFile could not be opened
        std::cerr << "Error opening output file." << std::endl;
        // Returning 1 to signify unsuccessful run of the program
        return 1;
    }
}
