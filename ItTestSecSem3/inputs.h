#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * \brief Get int user intput.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return int user input
 */
int getIntUserInput(std::string welcomeMessage, int min = 0, int max = INT_MAX);

std::vector<std::string> getMultilineString(std::string welcomeMessage);