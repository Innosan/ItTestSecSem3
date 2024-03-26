#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "files.h"
#include "inputs.h"
#include "validation.h"

using namespace std;

// Function to prompt user for overwrite confirmation
bool confirmOverwrite(const std::string& filename) {
	std::cout << "File '" << filename << "' already exists." << std::endl;
	std::cout << "Do you want to overwrite it? (y/n): ";

	char answer;
	std::cin >> answer;

	return std::tolower(answer) == 'y';
}

std::vector<std::string> getTextFromFile(const std::string& fileName) {
	std::vector<std::string> lines;

	std::ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		return lines; // Return empty vector on error
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}

	inputFile.close();
	return lines;
}

string getOverwriteConfirmation(const string& fullPath) {
	while (fileExists(fullPath)) {
		if (confirmOverwrite(fullPath)) {
			return fullPath;
		}
		else {
			cout << "Please choose another file." << endl;
			return getValidFilePath();
		}
	}
	return fullPath;
}

void exportToFile(const string& text) {
	string fullPath = getValidFilePath();
	fullPath = getOverwriteConfirmation(fullPath);

	// Try to open the file for writing
	ofstream file(fullPath);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		// Prompt the user to enter a new path
		while (true) {
			cout << "Please enter a new path." << endl;
			fullPath = getValidFilePath();
			fullPath = getOverwriteConfirmation(fullPath);

			// Try to open the new file for writing
			file.open(fullPath);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	file << text;

	file.close();
	std::cout << "Data successfully exported to file: " << fullPath << std::endl;
}
