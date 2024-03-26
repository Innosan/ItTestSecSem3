#include <iostream>
#include <regex>
#include <fstream>

#include "validation.h"
#include "inputs.h"

using namespace std;

bool isFilePathValid(const string& filePath) {

	// Regular expression to match a valid file path (Windows)
	regex filePathRegex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.txt$");

	if (!regex_match(filePath, filePathRegex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}

bool isFileNameValid(const string& fileName) {
	// Regular expression to match a valid file name
	regex fileNameRegex("^[^\\/:*?\"<>|]+\\.txt$");
	// Regular expression to match reserved file names in Windows
	regex fileNameReservedNames("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");
	// Regular expression to match reserved characters in Windows file names
	regex fileNameReservedChars("[\\/:*?\"<>|]");

	if (!regex_match(fileName, fileNameRegex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(fileName, fileNameReservedNames)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(fileName, fileNameReservedChars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string getValidFilePath() {
	bool isPathValid = false;
	bool isNameValid = false;

	string filename = "";
	string filepath = "";

	while (!isPathValid && !isNameValid) {
		filename = getStringUserInput("Input filename (only txt acceptable): ");
		filepath = getStringUserInput("Input full path to path: ");

		if (isFilePathValid(filepath + filename) && isFileNameValid(filename)) {
			isPathValid = true;
			isNameValid = true;
		}
	}

	return filepath + filename;
}

// Function to check if a file exists
bool fileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.is_open();
}