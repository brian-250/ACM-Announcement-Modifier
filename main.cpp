// importing standard C++ input/output stream library, allowing for usage of commands like std::cout or std::cin
#include <iostream>
// importing standard C++ file stream library, allowing for input and output operations to different files
#include <fstream>
// importing the standard C++ string library, allowing for the creation and maipulation of strings
#include <string>
// importing the standard C++ regular expression library, allowing for the use of regular expressions for pattern matching and replacements
#include <regex>

// Void function to replace strings from inputFile
// The string 'fullText' argument contains all lines of text from the inputFile
// Note: 'fullText' is passed by reference
void ReplaceText(std::string& fullText) {

    // 'fullText' calls std::regex_replace which takes three arguments to replace strings
    // The first argument is 'fullText' itself
    // The second argument is the string that is found in 'fullText' that needs to be replaced
    // The third argument is the new string that should replace the old string in argument two

    // Every 'str = ...' below does what is said in the previous comments above

    fullText = std::regex_replace(fullText, std::regex(R"(Reminders:[\s\S]*)"), "");

    fullText = std::regex_replace(fullText, std::regex("<:ai:1100135230054072380>"), "🤖");

    fullText = std::regex_replace(fullText, std::regex("<:algo:1100135231324958801>"), "🧑‍💻");
    
    fullText = std::regex_replace(fullText, std::regex("<:dev:1100135234168696934>"), "💻");

    fullText = std::regex_replace(fullText, std::regex("<:gamedev:1100135239247990854>"), "🎮");

    fullText = std::regex_replace(fullText, std::regex("<:design:1100135232507756666>"), "🎨");

    fullText = std::regex_replace(fullText, std::regex("<:acm:1100135227889815552>"), "😎");

    fullText = std::regex_replace(fullText, std::regex("<:oss:1100135621189713970>"), "🚀");

    fullText = std::regex_replace(fullText, std::regex("## "), "");

    fullText = std::regex_replace(fullText, std::regex("# "), "");

    fullText = std::regex_replace(fullText, std::regex("\\*\\*"), "");

    fullText = std::regex_replace(fullText, std::regex("\\* "), "");

    fullText = std::regex_replace(fullText, std::regex("@"), "");

    fullText = std::regex_replace(fullText, std::regex("‼️ Weekly Announcements ‼️"), "\n‼️ Weekly Announcements ‼️\n");

    fullText = std::regex_replace(fullText, std::regex(R"(<:matt:1209266095236710421>[\s\S]*)"), "");

    // Adds a new empty line after each line that contains the string 'Location:'
    fullText = std::regex_replace(fullText, std::regex("(Location:.*)"), "$1\n");
}

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

    // Declaring a string variable to hold each line of text from inputFile
    std::string line;
    // Declaring a string varibale to hold all lines of text from inputFile
    std::string fullText;

    // Reading each line of text from inputFile
    while (std::getline(inputFile, line)) {
        fullText += line; // Concatenating lines to build the fullText variable
        fullText += "\n"; // Adding a newline between lines to fullText variable
    }

    // Calling ReplaceAll() function to replace strings from inputFile and save into fullText variable
    ReplaceText(fullText);

    // Writing the modified text from fullText to outputFile and concatenating ACM at CSUF's cross-platform promotion links
    outputFile << fullText << "Join our Discord: acmcsuf.com/d\n" 
                           << "Follow our TikTok: acmcsuf.com/tiktok\n"
                           << "Check out our LinkTree: linktr.ee/acmcsuf";

    // Closing inputFile after reading it
    inputFile.close();
    // Closing outputFile after writing to it
    outputFile.close();

    // Message printed when exceutable file is run
    std::cout << "file1.txt modifications have now been made and written to file2.txt" << std::endl;

    // Returning 0 signifies successful run of the program
    return 0;
}
