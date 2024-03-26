#pragma once

#include <iostream>
#include <vector>

using namespace std;

/**
 * \brief Prompt user for overwrite confirmation.
 *
 * \param filename - name of the file to overwrite
 *
 * \return true if the user confirms the overwrite, false otherwise
 */
bool confirmOverwrite(const std::string& filename);

/**
 * Reads data from a file and constructs a vector of File objects.
 *
 * \param fileName The name of the file to read.
 * \return A vector of File objects, or an empty vector if there was an error.
 */
std::vector<std::string> getTextFromFile(const std::string& fileName);

/**
 * Exports data to a file.
 *
 * \param filesToExport A vector of File objects to export.
 */
void exportToFile(const string& text);